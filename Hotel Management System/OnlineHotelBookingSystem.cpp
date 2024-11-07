#include "OnlineHotelBookingSystem.hpp"

int OnlineHotelBookingSystem::paymentId;
int OnlineHotelBookingSystem::reservationId;
OnlineHotelBookingSystem* OnlineHotelBookingSystem::instance = nullptr;

OnlineHotelBookingSystem* OnlineHotelBookingSystem::getInstance(){
    if(instance == nullptr){
        instance = new OnlineHotelBookingSystem();
    }
    return instance;
}

void OnlineHotelBookingSystem::addHotel(Hotel* hotel) {
    hotels[hotel->getLocation()].emplace_back(hotel);
    hotelMap.insert({hotel->getHotelName(), hotel});
}

void OnlineHotelBookingSystem::loadRoomsToTheHotel(Hotel* hotel){
    hotel->addRoom(new Room(1, RoomType::SINGLE));
    hotel->addRoom(new Room(2, RoomType::SINGLE));
    hotel->addRoom(new Room(3, RoomType::DOUBLE));
    hotel->addRoom(new Room(4, RoomType::DOUBLE));
    hotel->addRoom(new Room(5, RoomType::DOUBLE));
    hotel->addRoom(new Room(6, RoomType::DELUX));
    hotel->addRoom(new Room(7, RoomType::DELUX));
    hotel->addRoom(new Room(8, RoomType::DELUX));
    hotel->addRoom(new Room(9, RoomType::DELUX));
    hotel->addRoom(new Room(10, RoomType::DELUX));
    hotel->addRoom(new Room(11, RoomType::SUITE));
    hotel->addRoom(new Room(12, RoomType::SUITE));
    hotel->addRoom(new Room(13, RoomType::SUITE));
    hotel->addRoom(new Room(14, RoomType::SUITE));
    hotel->addRoom(new Room(15, RoomType::SUITE));
    hotel->addRoom(new Room(16, RoomType::SUITE));
}

Reservation* OnlineHotelBookingSystem::searchHotelInTheLocation(Guest* user, string location) {
    if (hotels.find(location) == hotels.end() || hotels[location].empty()) {
        cout << "No hotels available at this location." << endl;
        return nullptr;
    }
    
    // List available hotels
    vector<Hotel*> availableHotels = hotels[location];
    cout << "\n-------- Available Hotels at " << location << " --------" << endl;
    int index = 1;
    for (auto hotel : availableHotels) {
        cout << index << ") " << hotel->getHotelName() << endl;
        index++;
    } 
    
    string hotelName;
    cout << "\nEnter Hotel Name: ";
    //cin.ignore(); Biggest Mistake that you include this line
    getline(cin, hotelName);

    Hotel* h = hotelMap[hotelName];

    return bookRoom(user, h);
}


Reservation* OnlineHotelBookingSystem::bookRoom(Guest* user, Hotel* hotel){
    cout<<"\n-------- Available Rooms --------"<<endl;
    hotel->availableRoomsInHotel();

    int roomNo;
    cout<<"Enter the Room No: ";
    cin>>roomNo;

    if(hotel->isRoomNoAvailable(roomNo)){
        Room* room = hotel->getRoom(roomNo);
        int checkInDate, checkOutDate;
        cout<<"Enter checkIn and CheckOut Dates: ";
        cin>>checkInDate>>checkOutDate;
        cout<<endl;

        Payment* payment = makePayment(user, room, hotel, checkInDate, checkOutDate);
        if(payment != nullptr){
            int reservationID = generateReservationId();
            Reservation* newRoomBooking = new Reservation(reservationID, user, hotel, room, payment->getAmount(),checkInDate, checkOutDate);
            room->roomBooked();
            hotel->bookRoom(room);
            user->addReservation(newRoomBooking);
            hotel->addReceipt(newRoomBooking);
            reservationHistory[reservationID] = newRoomBooking;
            return newRoomBooking;
        }
    }
    
    return nullptr;
}

void OnlineHotelBookingSystem::cancelRoomBooking(int id){
    Reservation* reservation = nullptr;
    if(reservationHistory.find(id) == reservationHistory.end()){
        cout<<"Such reservation havent taken place !!"<<endl;
        return;
    }
    this_thread::sleep_for(chrono::seconds(3));
    cout<<"\nProceeding for Cancellation"<<endl;
    reservation = reservationHistory[id];
    Room* room = reservation->getRoom();
    Hotel* hotel = reservation->getHotel();
    int amount = reservation->getAmount();
    if(room->getRoomStatus() == RoomStatus::OCCUPIED){

        reservation->markAsCancelled();
        hotel->cancelRoom(room);
        room->roomVacate();
        Payment* refund = new Credit(generatePaymentId(), reservation->getGuest()->getAccount(), amount);
        refund->execute();
        refundHistory[refund->getPaymentId()] = refund;
        cout<<"Cancelled Successfully :)"<<endl;
        cout<<"Refund Successfully!!"<<endl;
    }
}

Payment* OnlineHotelBookingSystem::makePayment(Guest* user, Room* room, Hotel* hotel, int checkInDate, int checkOutDate){
    int price = room->getPrice();
    cout<<"Room Price: "<<price<<endl;
    int amount = price * (checkOutDate - checkInDate);
    cout<<"As you stay for "<<checkOutDate - checkInDate<<" the total amount is: "<<amount<<endl;

    cout<<"\n-------- Redirecting to your bank website --------"<<endl;
    this_thread::sleep_for(chrono::seconds(2));
    int accNo, pin;
    Account* account = user->getAccount();

    cout<<"Enter Account No: ";
    cin>>accNo;
    cout<<"Enter Pin No: ";
    cin>>pin;

    if(account->getAccountNo() == accNo && account->getPin() == pin){
        cout<<"\n-------- Welcome --------"<<endl;
        if(amount > account->getBalance()){
            cout<<"Insufficient Funds"<<endl;
            exit(0);
        }

        cout<<"Payment Processing This could take couple of seconds!!"<<endl;
        this_thread::sleep_for(chrono::seconds(3));

        Payment* payment = new Debit(generatePaymentId(), account, amount);
        payment->execute();
        
        cout<<"Booked Successfully !!!"<<endl;
        return payment;
    }else{
        cout<<"Invalid Credentials"<<endl;
        exit(0);
    }

    return nullptr;    
}

void OnlineHotelBookingSystem::viewSummary(Reservation* reservation){
    cout<<"\n-------- Booking Summary --------"<<endl;
    cout<<"Hotel Name: "<<reservation->getHotel()->getHotelName()<<endl;
    cout<<"Hotel Location: "<<reservation->getHotel()->getLocation()<<endl;
    cout<<"Amount: "<<reservation->getAmount()<<endl;
}

int OnlineHotelBookingSystem::generatePaymentId(){
    return paymentId++;
}

int OnlineHotelBookingSystem::generateReservationId(){
    return reservationId++;
}

