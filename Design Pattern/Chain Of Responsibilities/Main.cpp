#include <iostream>
#include "LogProcessor.hpp"
#include "InfoLogProcessor.hpp"
#include "DebugLogProcessor.hpp"
#include "ErrorLogProcessor.hpp"
using namespace std;

// int main(){
//     LogProcessor* logobject = new InfoLogProcessor(new DebugLogProcessor(new DebugLogProcessor(nullptr)));
    
//     logobject->log(LogProcessor::INFO, "Just for Info");
//     logobject->log(LogProcessor::DEBUG, "need to debug");
//     logobject->log(LogProcessor::ERROR, "Exception happens");
// }

int main() {
    LogProcessor *logProcessor = new InfoLogProcessor(new DebugLogProcessor(new ErrorLogProcessor(NULL)));
    logProcessor->log(logProcessor->ERROR, "get error");
}