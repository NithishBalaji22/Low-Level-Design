#pragma once
#include <iostream>
#include "LogProcessor.hpp"
using namespace std;

class ErrorLogProcessor : public LogProcessor{
    public:
        ErrorLogProcessor(LogProcessor* nextLogProcessor) : LogProcessor(nextLogProcessor) {};

        void log(int logLevel, string message){
            if(logLevel == ERROR){
                cout<<"Error "<<message<<endl;
            }else{
                LogProcessor::log(logLevel, message);
            }
        }

};