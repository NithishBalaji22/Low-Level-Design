#pragma once
#include <iostream>
#include "DataAnalyticsTool.hpp"
using namespace std;

class Client{
    private:
        DataAnalyticsTool* tool;

    public:
        Client(DataAnalyticsTool* tool){
            this->tool = tool;
        }  

        void processData(){
            tool->analyseData();
        }
};