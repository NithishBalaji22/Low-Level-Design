#include <iostream>
#include <vector>
#include "Expression.hpp"
#include "ExpressionOperation.hpp"
#include "Term.hpp"
using namespace std;

int main(){
    int numOfTermsInExpressionOne;
    cout<<"Enter the number of terms in Expression 1: ";
    cin>>numOfTermsInExpressionOne;

    vector<Term*> expressionOneTerms(numOfTermsInExpressionOne);

    for(int i=0; i<expressionOneTerms.size(); i++){
        Term* term = new Term();
        cout<<"Enter the Term"<<endl;
        int coefficient;
        cout<<"Enter the coefficient of the term: "<<endl;
        cin>>coefficient;
        term->setCoefficient(coefficient);
        int xPower;
        cout<<"Enter the X power"<<endl;
        cin>>xPower;
        term->setVariableOne(xPower);
        int yPower;
        cout<<"Enter the Y power"<<endl;
        cin>>yPower;
        term->setVariableTwo(yPower);
        int zPower;
        cout<<"Enter the Z power"<<endl;
        cin>>zPower;
        term->setVariableThree(zPower);
        expressionOneTerms[i] = term;
    }

    Expression* expressionOne = new Expression(numOfTermsInExpressionOne);
    expressionOne->setTerms(expressionOneTerms);

    int numOfTermsInExpressionTwo;
    cout<<"Enter the number of terms in Expression 2: "<<endl;
    cin>>numOfTermsInExpressionTwo;

    vector<Term*> expressionTwoTerms(numOfTermsInExpressionTwo);

    for(int i=0; i<expressionTwoTerms.size(); i++){
        Term* term = new Term();
        cout<<"Enter the Term"<<endl;
        int coefficient;
        cout<<"Enter the coefficient of the term: "<<endl;
        cin>>coefficient;
        term->setCoefficient(coefficient);
        int xPower;
        cout<<"Enter the X power"<<endl;
        cin>>xPower;
        term->setVariableOne(xPower);
        int yPower;
        cout<<"Enter the Y power"<<endl;
        cin>>yPower;
        term->setVariableTwo(yPower);
        int zPower;
        cout<<"Enter the Z power"<<endl;
        cin>>zPower;
        term->setVariableThree(zPower);
        expressionTwoTerms[i] = term;
    }

    Expression* expressionTwo = new Expression(numOfTermsInExpressionTwo);
    expressionTwo->setTerms(expressionTwoTerms);

    ExpressionOperator* expressionOperator = new ExpressionOperator();
    expressionOperator->evaluateExpressions(expressionOne, expressionTwo);
}