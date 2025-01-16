#pragma once
#include <iostream>
using namespace std;

class LogProcessor{
    public:
        const static int INFO = 1;
        const static int DEBUG = 2;
        const static int ERROR = 3;
        LogProcessor* nextLogProcessor;

        LogProcessor(LogProcessor* nextLogProcessor){
            this->nextLogProcessor = nextLogProcessor;
        }

        virtual void log(int logLevel, string message){
            if(nextLogProcessor != nullptr){
                nextLogProcessor->log(logLevel, message);
            }
        }
};