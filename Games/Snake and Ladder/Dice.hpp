#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Dice {
    public:
        Dice() {
            srand(time(0)); 
        }

        int roll() {
            return (rand() % 6) + 1; // Generate a number from 1 to 6
        }
};
