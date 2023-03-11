#ifndef TUBESOOP_CARDS_HPP
#define TUBESOOP_CARDS_HPP
#include <string>
#include "hand.hpp"

class Card : public virtual Hand {
public:
    Card(int, Color);
//  int getNumber() const;
//  string getColor();
    float value() const override;
    bool operator>(Card&);
    bool operator<(Card&);
    bool operator==(Card&);
    bool operator!=(Card&);
    bool operator>=(Card&);
    bool operator<=(Card&);
protected:
    const int number;
    const Color color;
};

// TODO: Implementasi class PlayerCard dan AbilityCard
class PlayerCard : public Card {
    public:
        PlayerCard(int, Color);
};

class AbilityCard : public Card {
    public:
        AbilityCard(int, Color);
};

#endif
