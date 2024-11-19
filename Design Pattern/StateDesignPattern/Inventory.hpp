#pragma once
#include <iostream>
#include <unordered_map>
#include "Product.hpp"
using namespace std;

class Inventory{
    private:
        unordered_map<int, Product*> products;
    public:
        Inventory(){
            products = unordered_map<int, Product*>();
        }

        void addProduct(Product* product){
            products[product->getProductId()] = product;
        }

        int getProductCost(int productId){
            return products[productId]->getProductCost();
        }

        Product* getProduct(int productId){
            return products[productId];
        }

        bool isProductAvailable(int productId){
            if(products.find(productId) != products.end()){
                int productQuantity = products[productId]->getQuantity();
                if(productQuantity > 0){
                    cout<<"We could fullfill you required Quantity !!"<<endl;
                    return true;
                }else{
                    cout<<"We couldnt fullfill your requirement Sorry!!"<<endl;
                    return false;
                }
            }

            cout<<"The product Id aint exits in our inventory!!";
            return false;
        }

        void updateProductQuantity(int productId, int quantity){
            if(products.find(productId) != products.end()){
                products[productId]->updateQuantity(quantity);
            }else{
                cout<<"Product with that ID couldnt found !!"<<endl;
                return;
            }
        }

        void decreseProductQuantity(int productId, int quantity){
            if(products.find(productId) != products.end()){
                products[productId]->decrementQuantity(quantity);
            }else{
                cout<<"Product with that ID couldnt found !!"<<endl;
                return;
            }
        }
};