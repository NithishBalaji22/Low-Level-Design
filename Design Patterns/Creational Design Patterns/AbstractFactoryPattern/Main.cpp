#include <iostream>
#include "Buttons.hpp"
#include "GUIFactory.hpp"
#include "IFactory.hpp"
#include "TextBox.hpp"
using namespace std;

int main(){
    string osType;
    cout<<"Enter the Os: ";
    cin>>osType;

    Ifactory* fact = GUIFactory::createFactory(osType);

    IButton* button = fact->createButton();
    button->pressButton();

    ITestBox* textBox = fact->createTextBox();
    textBox->showText();
}