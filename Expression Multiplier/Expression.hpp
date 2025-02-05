#pragma once
#include <iostream>
#include <vector>
#include "Term.hpp"
using namespace std;

class Expression{
    private:
        int noOfTerms;
        vector<Term*> terms;

    public:
        Expression(int noOfTerms){
            this->noOfTerms = noOfTerms;
            terms = vector<Term*>(noOfTerms);
        }

        void setTerms(vector<Term*> terms){
            this->terms = terms;
        }

        vector<Term*> getTerms(){
            return terms;
        }
};