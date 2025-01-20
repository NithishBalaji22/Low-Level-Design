#include <iostream>
#include "DataAnalyticsTool.hpp"
#include "XMLData.hpp"
#include "Client.hpp"
using namespace std;

int main(){
    XMLData* xmlData = new XMLData("XML_Data");
    DataAnalyticsTool* tool = new Adaptor(xmlData);
    Client* client = new Client(tool);
    client->processData();
}