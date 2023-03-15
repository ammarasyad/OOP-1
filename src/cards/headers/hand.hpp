#ifndef TUBESOOP_HAND_HPP
#define TUBESOOP_HAND_HPP
#include <string>
#include <map>

enum Color {
    GREEN = 0,
    BLUE = 1,
    YELLOW = 2,
    RED = 3
};

class Hand {
public:
    virtual float getValue() = 0;
};

#endif
