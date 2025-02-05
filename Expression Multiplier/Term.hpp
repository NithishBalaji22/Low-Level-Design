#pragma once
#include <iostream>
using namespace std;

class Term{
    private:
        int coefficient;
        int variableOne;
        int variableTwo;
        int variableThree;

    public:
        Term() {}

        void setCoefficient(int coefficient){
            this->coefficient = coefficient;
        }

        void setVariableOne(int variableOne){
            this->variableOne = variableOne;
        }

        void setVariableTwo(int variableTwo){
            this->variableTwo = variableTwo;
        }

        void setVariableThree(int variableThree){
            this->variableThree = variableThree;
        }

        int getCoefficient(){
            return coefficient;
        }

        int getVariableOne(){
            return variableOne;
        }

        int getVariableTwo(){
            return variableTwo;
        }

        int getVariableThree(){
            return variableThree;
        }
};