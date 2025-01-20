#pragma once
#include <iostream>
using namespace std;

class ATMProcessor{
    public:
        static int thousands;
        static int fiveHundreds;
        static int hundred;
        ATMProcessor* nextProcessor;

        ATMProcessor(ATMProcessor* nextProcessor){
            this->nextProcessor = nextProcessor;
            thousands = 5;
            fiveHundreds = 10;
            hundred = 15;
        }

        virtual void log(int amount){
            if(nextProcessor != nullptr){
                nextProcessor->log(amount);
            }
        }

        void reduceThousands(int denomination){
            thousands -= denomination;
        }

        void reduceFiveHundreds(int denomination){
            fiveHundreds -= denomination;
        }

        void reduceHundreds(int denomination){
            hundred -= denomination;
        }

        void showDenominations(){
            cout<<"1000: "<<thousands<<endl;
            cout<<"500: "<<fiveHundreds<<endl;
            cout<<"100: "<<hundred<<endl;
        }
};

class ThousandHandler : public ATMProcessor{
    public:
        ThousandHandler(ATMProcessor* nextProcessor) : ATMProcessor(nextProcessor) {}
        void log(int amount){
            if(amount >= 1000 && ATMProcessor::thousands > 0){
                int amt = amount;
                int maxTake = amt / 1000;
                int canTake = min(maxTake, ATMProcessor::thousands);
                amt -= (1000 * canTake);
                cout<<"Amount Processed is: "<< "1000 * "<<canTake<<" : "<<(1000 * canTake)<<endl;
                ATMProcessor::reduceThousands(canTake);
                if(amt > 0){
                    ATMProcessor::log(amt);
                }
            }else{
                ATMProcessor::log(amount);
            }
        }
};


class FiveHunderedHandler : public ATMProcessor{
    public:
        FiveHunderedHandler(ATMProcessor* nextProcessor) : ATMProcessor(nextProcessor) {}
        void log(int amount){
            if(amount >= 500 && ATMProcessor::fiveHundreds > 0){
                int amt = amount;
                int maxTake = amt / 500;
                int canTake = min(maxTake, ATMProcessor::fiveHundreds);
                amt -= (500 * canTake);
                cout<<"Amount Processed is: "<< "500 * "<<canTake<<" : "<<(500 * canTake)<<endl;
                ATMProcessor::reduceFiveHundreds(canTake);
                if(amt > 0){
                    ATMProcessor::log(amt);
                }
            }else{
                ATMProcessor::log(amount);
            }
        }
};

class HunderedHandler : public ATMProcessor{
    public:
        HunderedHandler(ATMProcessor* nextProcessor) : ATMProcessor(nextProcessor) {}
        void log(int amount){
            if(amount >= 100 && ATMProcessor::hundred > 0){
                int amt = amount;
                int maxTake = amt / 100;
                int canTake = min(maxTake, ATMProcessor::hundred);
                amt -= (100 * canTake);
                cout<<"Amount Processed is: "<< "100 * "<<canTake<<" : "<<(100 * canTake)<<endl;
                ATMProcessor::reduceHundreds(canTake);
                if(amt > 0){
                    ATMProcessor::log(amt);
                }
            }else{
                ATMProcessor::log(amount);
            }
        }
};
