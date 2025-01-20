#include <iostream>
#include "ATMProcessor.hpp"
using namespace std;

int ATMProcessor::thousands;
int ATMProcessor::fiveHundreds;
int ATMProcessor::hundred;

int main(){
    ATMProcessor* processor = new ThousandHandler(new FiveHunderedHandler(new HunderedHandler(nullptr)));
    processor->log(2000);
    processor->showDenominations();
    
}