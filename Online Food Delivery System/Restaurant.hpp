#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class MenuItem;
class Order;
class Restaurant{
    private:
        int id;
        string name;
        char location;
        vector<MenuItem*> menuItems;
        unordered_map<string, MenuItem*> menuItemMaps;
        vector<Order*> orderHistory;
    
    public:
        Restaurant(int id, string name, char location){
            this->id = id;
            this->name = name;
            this->location = location;
            menuItems = vector<MenuItem*>();
            menuItemMaps = unordered_map<string, MenuItem*>();
            orderHistory = vector<Order*>();
        }

        string getRestaurantName(){
            return name;
        }

        MenuItem* getMenuItem(string name){
            return menuItemMaps[name];
        }

        void addMenuItem(MenuItem* item){
            menuItemMaps.insert({item->getName(), item});
            menuItems.emplace_back(item);            
        }

        void removeItem(MenuItem* itemToRemove){
            auto item = find(menuItems.begin(), menuItems.end(), itemToRemove);
            if(item != menuItems.end()){
                menuItems.erase(item);
            }
        }

        void addOrder(Order* order){
            orderHistory.emplace_back(order);
        }

        char getRestaurantLocation(){
            return location;
        }

        vector<MenuItem*> getMenu(){
            return menuItems;
        }
};