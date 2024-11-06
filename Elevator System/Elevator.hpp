#pragma once
#include <iostream>
#include <queue>
#include <thread>
#include "Direction.hpp"
#include "Request.hpp"
using namespace std;

class Elevator{
    private:
        int elevatorId;
        int currentFloor;
        int capacity;
        Direction direction;
        bool underMaintanance;
        bool isAvailable;
        queue<Request*> requests;

    public:
        Elevator(int id, int currentFloor, int capacity, Direction direction){
            this->elevatorId = id;
            this->currentFloor = currentFloor;
            this->direction = direction;
            this->capacity = capacity;
            underMaintanance = false;
            isAvailable = true;
            requests = queue<Request*>();
            direction = Direction::UP;
        }

        int getId(){
            return elevatorId;
        }

        int getCurrentFloor(){
            return currentFloor;
        }

        void setCurrentFloor(int floor){
            currentFloor = floor;
        }

        Direction getDirection(){
            return direction;
        }

        void setDirection(Direction direction){
            this->direction = direction;
        }

        bool isUnderMaintance(){
            return underMaintanance;
        }

        void setUnderMaintanance(){
            underMaintanance = true;
        }

        void unsetUnderMaintanace(){
            underMaintanance = false;
        }

        void notAvailable(){
            isAvailable = false;
        }

        void available(){
            isAvailable = true;
        }

        void addRequest(Request* request){
            if(underMaintanance){
                cout<<"We cannot handle this request at this moment due to maintanance sorry for the inconvinience\n";
                return;
            }
            if(requests.size() == capacity){
                cout<<"We cannot handle this request at this moment sorry for the inconvinience\n";
                return;
            }
            requests.push(request);
        }

        void processRequest(){
            while(!requests.empty()){
                Request* request = requests.front();
                requests.pop();
                processRequest(request);
            }
        }

        void processRequest(Request* request){
            int userSource = request->getSource();
            int userDestination = request->getDestination();

            if(currentFloor > userSource){
                // Then we have to go down first right to pick up the customer
                notAvailable();
                setDirection(Direction::DOWN);
                for(int i=currentFloor; i >= userSource; i--){
                    cout<<"Current Floor is: "<<i<<endl;
                    setCurrentFloor(i);
                    this_thread::sleep_for(chrono::seconds(2));
                }
                
                if(userDestination > userSource){
                    setDirection(Direction::UP);
                    for(int i=userSource; i <= userDestination; i++){
                        cout<<"Current Floor is: "<<i<<endl;
                        setCurrentFloor(i);
                        this_thread::sleep_for(chrono::seconds(2));
                    }
                }else{
                    setDirection(Direction::DOWN);
                    for(int i=userSource; i >= userDestination; i--){
                        cout<<"Current Floor is: "<<i<<endl;
                        setCurrentFloor(i);
                        this_thread::sleep_for(chrono::seconds(2));
                    }
                }
                available();
            }else if(currentFloor < userSource){
                //Then First We have to go up first right to pick up the customer
                notAvailable();
                setDirection(Direction::UP);
                for(int i=currentFloor; userSource >= i; i++){
                    cout<<"Current Floor is: "<<i<<endl;
                    setCurrentFloor(i);
                    this_thread::sleep_for(chrono::seconds(2));
                }
                
                if(userDestination > userSource){
                    setDirection(Direction::UP);
                    for(int i=userSource; i <= userDestination; i++){
                        cout<<"Current Floor is: "<<i<<endl;
                        setCurrentFloor(i);
                        this_thread::sleep_for(chrono::seconds(2));
                    }
                }else{
                    setDirection(Direction::DOWN);
                    for(int i=userSource; i >= userDestination; i--){
                        cout<<"Current Floor is: "<<i<<endl;
                        setCurrentFloor(i);
                        this_thread::sleep_for(chrono::seconds(2));
                    }
                }
                available();
            }else{
                //Both the user and the lift are at the same level
                notAvailable();
                if(userDestination > userSource){
                    setDirection(Direction::UP);
                    for(int i=userSource; i <= userDestination; i++){
                        cout<<"Current Floor is: "<<i<<endl;
                        setCurrentFloor(i);
                        this_thread::sleep_for(chrono::seconds(2));
                    }
                }else{
                    setDirection(Direction::DOWN);
                    for(int i=userSource; i >= userDestination; i--){
                        cout<<"Current Floor is: "<<i<<endl;
                        setCurrentFloor(i);
                        this_thread::sleep_for(chrono::seconds(2));
                    }
                }
                available();
            }
        }

        void run(){
            processRequest();
        }
};