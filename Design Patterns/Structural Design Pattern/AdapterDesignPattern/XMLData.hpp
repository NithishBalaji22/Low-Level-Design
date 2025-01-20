#pragma once
#include <iostream>
using namespace std;

class XMLData{  
    private:
        string xmlData;

    public:
        XMLData(string xmlData){
            this->xmlData = xmlData;
        }

        string getXMLData(){
            return xmlData;
        }
};