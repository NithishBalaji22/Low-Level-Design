#pragma once
#include <bits/stdc++.h>
#include "Room.hpp"
#include "Reservation.hpp"
using namespace std;

class Hotel{
    private:
        string hotelName;
        string location;
        string contactNo;
        unordered_map<int, Room*> availableRooms;
        unordered_map<int, Room*> bookedRooms;
        unordered_map<int, Reservation*> receipt;

    public:
        Hotel(string hotelName, string location, string contactNo){
            this->hotelName = hotelName;
            this->location = location;
            this->contactNo = contactNo;
            availableRooms = unordered_map<int, Room*>();
            bookedRooms = unordered_map<int, Room*>();
        }

        string getLocation(){
            return location;
        }

        string getHotelName(){
            return hotelName;
        }

        void addRoom(Room* room){
            availableRooms[room->getRoomNo()] = room;
        }

        void availableRoomsInHotel(){
            cout<<"Room Id\tRoom Type\tRoom Price"<<endl;
            for(auto room : availableRooms){
                room.second->aboutTheRoom(room.second);
            }
        }

        bool isRoomNoAvailable(int roomNo){
            if(availableRooms.find(roomNo) != availableRooms.end()){
                return true;
            }
            return false;
        }

        Room* getRoom(int roomNo){
            return availableRooms[roomNo];
        }

        void bookRoom(Room* room){
            int roomNo = room->getRoomNo();
            availableRooms.erase(roomNo);
            bookedRooms[roomNo] = room;
        }

        void cancelRoom(Room* room){
            int roomNo = room->getRoomNo();
            bookedRooms.erase(roomNo);
            availableRooms[roomNo] = room;
        }

        void addReceipt(Reservation* reservation){
            receipt.insert({reservation->getReservationId(), reservation});
        }

        Reservation* getReceipt(int reservationId){
            if(receipt.find(reservationId) != receipt.end()){
                return receipt[reservationId];
            }
            return nullptr;
        }
};
