#pragma once
#include <iostream>
#include <stack>
#include "Memento.hpp"
using namespace std;

class CareTaker {
private:
    stack<Memento*> originatorObjHistory;

public:
    CareTaker() = default;

    void addMemento(Memento* memento) {
        originatorObjHistory.push(memento);
    }

    Memento* undo() {
        if (originatorObjHistory.empty()) {
            cout << "No previous state to restore!" << endl;
            return nullptr;
        }

        // Retrieve the top state but do not remove it
        Memento* lastState = originatorObjHistory.top();
        originatorObjHistory.pop();
        return lastState;
    }
};
