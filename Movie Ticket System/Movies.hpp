#pragma once
#include<iostream>
using namespace std;

enum Ratings{
    FIVE_STAR,
    FOUR_STAR,
    THREE_STAR,
    TWO_STAR,
    ONE_STAR
};

class Movies{
    private:
        int id;
        string title;
        string description;
        Ratings rating;
        int duration;

    public:
        Movies(int id, string title, string description, Ratings rating, int duration){
            this->id = id;
            this->title = title;
            this->description = description;
            this->rating = rating;
            this->duration = duration;
        }

        void setRatings(Ratings rating){
            this->rating = rating;
        }

        int getId(){
            return id;
        }

        string getTitle(){
            return title;
        }

        Ratings getRatings(){
            return rating;
        }

        int getDuration(){
            return duration;
        }
};