#pragma once
#include<bits/stdc++.h>
using namespace std;

class MenuItem;
class Restaurant{
    private:
        string id;
        string name;
        string location;
        unordered_map<string, MenuItem*> items;

    public: 
        Restaurant(string id, string name, string locations, unordered_map<string, MenuItem*> items){
            this->id = id;
            this->name = name;
            this->location = location;
            this->items = items;
        }

        string getRestaurantId(){
            return id;
        }

        vector<MenuItem*> getMenuItems(){
            vector<MenuItem*> v;
            for(auto it : items){
                v.emplace_back(it.second);
            }
            return v;
        }

        // void addMenuItem(string itemName, MenuItem* item){
        //     items.insert({itemName, item});
        // }

        void addMenuItem(string itemName, MenuItem* item){
            if(items.find(itemName) == items.end()){
                items[itemName] = item;
            }else{
                cout << "Item with name " << itemName << " already exists." << endl;
            }
        }       


        // void removeItem(string itemName){
        //     items.erase(itemName);
        // }

        void removeItem(string itemName){
            if(items.find(itemName) != items.end()){
                items.erase(itemName);
            }else{
                cout << "Item with name " << itemName << " not found." << endl;
            }
        }

};

