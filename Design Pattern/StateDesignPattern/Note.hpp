#pragma once
#include<iostream>
using namespace std;

enum Note{
    FIVE_RUPPEE_NOTE = 5,
    TEN_RUPPEE_NOTE = 10,
    TWENTY_RUPPEE_NOTE = 20,
    FIFTY_RUPPEE_NOTE = 50
};

class NoteValue{
    public:
        int getNoteValue(Note note){
            switch(note){
                case Note::FIVE_RUPPEE_NOTE : return 5;
                case Note::TEN_RUPPEE_NOTE : return 10;
                case Note::TWENTY_RUPPEE_NOTE : return 20;
                case Note::FIFTY_RUPPEE_NOTE : return 50;
            }
        }
};