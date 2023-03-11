#ifndef TUBESOOP_HAND_HPP
#define TUBESOOP_HAND_HPP
#include <string>
using namespace std;

enum Color {
    GREEN = 1,
    BLUE = 2,
    YELLOW = 3,
    RED = 4
};

string colorToString(Color color) {
    switch (color) {
        case GREEN:
            return "Green";
        case BLUE:
            return "Blue";
        case YELLOW:
            return "Yellow";
        case RED:
            return "Red";
    }
}

class Hand {
public:
    virtual int value() = 0;
};

#endif
