#include <iostream>
#include "Caretaker.hpp"
#include "Memento.hpp"
#include "Originator.hpp"
using namespace std;

int main() {
    CareTaker* careTaker = new CareTaker();
    Originator* originator = new Originator(10, 20);

    // Save initial state
    Memento* snapShot1 = originator->createSnapshot();
    careTaker->addMemento(snapShot1);

    originator->setHeight(30);
    originator->setWidth(40);

    // Save modified state
    Memento* snapShot2 = originator->createSnapshot();
    careTaker->addMemento(snapShot2);

    // Display current state
    cout << "Current State:" << endl;
    originator->showHeightWidth();

    // Undo to previous state
    Memento* prevState = careTaker->undo();
    if (prevState) {
        originator->restoreMemento(prevState);
        cout << "Restored to Previous State:" << endl;
        originator->showHeightWidth();
    }

    // Clean up
    delete careTaker;
    delete originator;

    return 0;
}
