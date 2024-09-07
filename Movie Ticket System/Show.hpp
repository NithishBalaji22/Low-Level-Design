#pragma once
#include <bits/stdc++.h>
using namespace std;

class Theater;
class Movies;
class Seats;

class Shows{
    private:
        int id;
        string location;
        Theater* theater;
        Movies* movies;
        unordered_map<string, Seats*>seats;

    public:
        Shows(int id, string location, Theater* theater, Movies* movies, unordered_map<string, Seats*>seats){
            this->id = id;
            this->location = location;
            this->theater = theater;
            this->movies = movies;
            this->seats = seats;
        }

        int getId(){
            return id;
        }

        string getLocation(){
            return location;
        }

        Theater* getTheater(){
            return theater;
        }

        Movies* getMovie(){
            return movies;
        }  

        unordered_map<string, Seats*> getSeats(){
            return seats;
        }     
};