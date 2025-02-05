#pragma once
#include <iostream>
#include <vector>
#include "Expression.hpp"
#include "Term.hpp"
using namespace std;

class ExpressionOperator{
    public:
        ExpressionOperator(){}

        void evaluateExpressions(Expression* experssionOne, Expression* expressiontwo){
            for(Term* term1 : experssionOne->getTerms()){
                for(Term* term2 : expressiontwo->getTerms()){
                    Term* result = new Term();
                    result->setCoefficient(term1->getCoefficient() * term2->getCoefficient());
                    cout<<result->getCoefficient();
                    result->setVariableOne(term1->getVariableOne() + term2->getVariableOne());
                    cout<<"X"<<result->getVariableOne();
                    result->setVariableTwo(term1->getVariableTwo() + term2->getVariableTwo());
                    cout<<"Y"<<result->getVariableTwo();
                    result->setVariableThree(term1->getVariableThree() + term2->getVariableThree());
                    cout<<"Z"<<result->getVariableThree();
                }
            }
        }
};