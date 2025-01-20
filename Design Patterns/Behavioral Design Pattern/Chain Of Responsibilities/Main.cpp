#include <iostream>
#include "LogProcessor.hpp"
#include "InfoLogProcessor.hpp"
#include "DebugLogProcessor.hpp"
#include "ErrorLogProcessor.hpp"
using namespace std;

int main() {
    LogProcessor *logProcessor = new InfoLogProcessor(new DebugLogProcessor(new ErrorLogProcessor(NULL)));
    logProcessor->log(logProcessor->ERROR, "get error");
}
