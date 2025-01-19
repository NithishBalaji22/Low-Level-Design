#pragma once
#include <iostream>
using namespace std;

class Prototype{
    public:
        virtual Prototype* clone() = 0;
};

class Student : public Prototype{
    private:
        int studentID;
        string name;
        int age;
        string gender;

    public:
        Student(int studentID, string name, int age, string gender){
            this->studentID = studentID;
            this->name = name;
            this->age = age;
            this->gender = gender;
        }

        void print(){
            cout<<"StudentID: "<<studentID<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Age: "<<age<<endl;
            cout<<"Gender: "<<gender<<endl;
        }

        Prototype* clone() override{
            return new Student(studentID, name, age, gender);
        }
};