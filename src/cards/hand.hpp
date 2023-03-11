#ifndef TUBESOOP_HAND_HPP
#define TUBESOOP_HAND_HPP
#include <string>
using namespace std;

enum Color {
    GREEN = 0,
    BLUE = 1,
    YELLOW = 2,
    RED = 3
};

//string colorToString(Color color) {
//    switch (color) {
//        case GREEN:
//            return "Green";
//        case BLUE:
//            return "Blue";
//        case YELLOW:
//            return "Yellow";
//        case RED:
//            return "Red";
//    }
//}

class Hand {
public:
    virtual float value() const = 0;
};

#endif
