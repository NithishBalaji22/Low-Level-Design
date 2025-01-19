#include <iostream>
#include "Student.hpp"
using namespace std;

int main(){
    Student* nithish = new Student(1, "Nithish", 21, "Male");
    Student* balaji = static_cast<Student*>(nithish->clone());
    balaji->print();
}