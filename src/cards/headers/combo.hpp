#ifndef TUBESOOP_COMBO_HPP
#define TUBESOOP_COMBO_HPP
#include <iostream>
#include <vector>
#include "hand.hpp"
#include "cards.hpp"

enum CombinationType {
    HIGH_PAIR = 0,
    PAIR = 1,
    TWO_PAIR = 2,
    THREE_OF_A_KIND = 3,
    STRAIGHT = 4,
    FLUSH = 5,
    FULL_HOUSE = 6,
    FOUR_OF_A_KIND = 7,
    STRAIGHT_FLUSH = 8,
};

class Combination : public Hand {
public:
    template <typename... PlayerCards>
    explicit Combination(PlayerCards...);
    explicit Combination(vector<PlayerCard>&);
    float getValue() override;
    vector<PlayerCard> getCards() const;
    CombinationType getType() const;
    PlayerCard& operator[](int);
//    bool operator>(Combination&);
//    bool operator<(Combination&);
//    bool operator==(Combination&);
//    bool operator!=(Combination&);
//    bool operator>=(Combination&);
//    bool operator<=(Combination&);
private:
    vector<PlayerCard> cards;
    CombinationType type;

    CombinationType calculateType();
    PlayerCard getHighestCard();
    float getComboTypeValue();
};

#endif
