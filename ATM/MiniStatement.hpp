#pragma once
#include <iostream>
using namespace std;

class MiniStatement{
    private:
        int id;
        string remark;
        string type;
        int amount;

    public:
        MiniStatement(int id, string remark, string type, int amount){
            this->id = id;
            this->remark = remark;
            this->type = type;
            this->amount = amount;
        }

        int getId(){
            return id;
        }

        string getRemark(){
            return remark;
        }

        string getType(){
            return type;
        }

        int getAmount(){
            return amount;
        }
};