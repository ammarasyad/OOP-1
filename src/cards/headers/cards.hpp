#ifndef TUBESOOP_CARDS_HPP
#define TUBESOOP_CARDS_HPP
#include <string>
#include "hand.hpp"

enum Ability {
    REROLL,
    QUADRUPLE,
    QUARTER,
    REVERSE_DIRECTION,
    SWAP,
    SWITCH,
    ABILITYLESS
};

map<Ability, string> abilityString = {
        {REROLL, "Reroll"},
        {QUADRUPLE, "Quadruple"},
        {QUARTER, "Quarter"},
        {REVERSE_DIRECTION, "Reverse Direction"},
        {SWAP, "Swap"},
        {SWITCH, "Switch"},
        {ABILITYLESS, "Abilityless"}
};

class Card : protected Hand {
public:
    virtual void print() = 0;
};

class PlayerCard : Card {
private:
    int number;
    Color color;
public:
    PlayerCard(int, Color);
    PlayerCard(const PlayerCard&);
    int getNumber() const;
    Color getColor();
    string getColorString();
    float getValue() override;
    void print() override;
    bool operator>(const PlayerCard&) const;
    bool operator<(const PlayerCard&) const;
    bool operator==(const PlayerCard&) const;
    bool operator!=(const PlayerCard&) const;
    bool operator>=(const PlayerCard&) const;
    bool operator<=(const PlayerCard&) const;
};

class AbilityCard : Card {
private:
    Ability ability;
public:
    explicit AbilityCard(Ability);
    AbilityCard(const AbilityCard&);
    virtual ~AbilityCard();
    Ability getAbility();
    void print() override;
    void consume();
};

#endif
