#pragma once
#include <iostream>
#include "LogProcessor.hpp"
using namespace std;

class DebugLogProcessor : public LogProcessor{
    public:
        DebugLogProcessor(LogProcessor* nextLogProcessor) : LogProcessor(nextLogProcessor) {};

        void log(int logLevel, string message){
            if(logLevel == DEBUG){
                cout<<"Debug "<<message<<endl;
            }else{
                LogProcessor::log(logLevel, message);
            }
        }

};