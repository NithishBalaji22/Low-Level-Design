#pragma once
#include <iostream>
#include "XMLData.hpp"
using namespace std;

class DataAnalyticsTool{
    private:
        string jsonData;

    public:
        DataAnalyticsTool() = default;
        DataAnalyticsTool(string jsonData){
            this->jsonData = jsonData;
        }

        virtual void analyseData(){
            cout<<"Analysing the JSON Data "<<jsonData<<endl;
        }
};

class Adaptor : public DataAnalyticsTool{
    private:
        XMLData* xmlData;
    public:
        Adaptor(XMLData* xmlData){
            this->xmlData = xmlData;
        }

        void analyseData(){
            cout<<"Converting the XML Data "<< xmlData->getXMLData() <<" to JSON Data"<<endl;
            DataAnalyticsTool::analyseData();
        }
};