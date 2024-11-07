#pragma once
#include <iostream>
#include "RoomType.hpp"
#include "RoomStatus.hpp"
using namespace std;

class Room{
    private:
        int roomNo;
        RoomType type;
        RoomStatus status;
        int price;

    public:
        Room(int roomNo, RoomType type){
            this->roomNo = roomNo;
            this->type = type;
            switch(type){
                case RoomType::SINGLE:
                    price = 1000;
                    break;
                
                case RoomType::DOUBLE:
                    price = 2500;
                    break;
                
                case RoomType::DELUX:
                    price = 5000;
                    break;
                case RoomType::SUITE:
                    price = 7000;
                    break;
            }
        }

        int getRoomNo(){
            return roomNo;
        }

        int getPrice(){
            return price;
        }

        RoomType getRoomType(){
            return type;
        }

        RoomStatus getRoomStatus(){
            return status;
        }

        void roomBooked(){
            status = RoomStatus::OCCUPIED;
        }

        void roomVacate(){
            status = RoomStatus::AVAILABLE;
        }

        string roomTypeString(RoomType type){
            if(type == RoomType::SINGLE) return "Single";
            else if(type == RoomType::DOUBLE) return "Double";
            else if(type == RoomType::DELUX) return "Delux";
            else return "Suits";
        }

        void aboutTheRoom(Room* room){
            cout<<roomNo<<'\t'<<roomTypeString(room->getRoomType())<<"\t\t"<<price<<endl;
        }
};

