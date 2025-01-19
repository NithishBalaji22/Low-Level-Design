#pragma once
#include <iostream>
#include "LogProcessor.hpp"
using namespace std;

class InfoLogProcessor : public LogProcessor{
    public:
        InfoLogProcessor(LogProcessor* nextLogProcessor) : LogProcessor(nextLogProcessor) {};

        void log(int logLevel, string message){
            if(logLevel == INFO){
                cout<<"Info "<<message<<endl;
            }else{
                LogProcessor::log(logLevel, message);
            }
        }

};