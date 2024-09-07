#pragma once
#include<bits/stdc++.h>
using namespace std;

class Shows;
class Seats;
class Theater{
    private:
        int id;
        string name;
        string location;
        vector<Shows*>shows;

    public:
        Theater(int id, string name, string location, vector<Shows*> shows){
            this->id = id;
            this->name = name;
            this->location = location;
            this->shows = shows; 
        }

        vector<Shows*> getShows(){
            return shows;
        }
};
