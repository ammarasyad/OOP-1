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
    explicit Combination(std::vector<PlayerCard>&);
    float getValue() override;
    std::vector<PlayerCard> getCards() const;
    CombinationType getType() const;
    std::string getTypeString();
    PlayerCard& operator[](int);
    bool operator>(Combination&);
    bool operator<(Combination&);
    bool operator==(Combination&);
    bool operator!=(Combination&);
    bool operator>=(Combination&);
    bool operator<=(Combination&);
private:
    std::vector<PlayerCard> cards;
    CombinationType type;
    std::map<CombinationType, std::string> comboString = {
            {HIGH_PAIR, "High Pair"},
            {PAIR, "Pair"},
            {TWO_PAIR, "Two Pair"},
            {THREE_OF_A_KIND, "Three of a Kind"},
            {STRAIGHT, "Straight"},
            {FLUSH, "Flush"},
            {FULL_HOUSE, "Full House"},
            {FOUR_OF_A_KIND, "Four of a Kind"},
            {STRAIGHT_FLUSH, "Straight Flush"}
    };

    PlayerCard& getHighestCard();
    CombinationType calculateType();
    bool isStraightFlush();
    bool isFourOfAKind();
    bool isFullHouse();
    bool isFlush();
    bool isStraight();
    bool isThreeOfAKind();
    bool isTwoPair();
    bool isPair();


};

#endif
