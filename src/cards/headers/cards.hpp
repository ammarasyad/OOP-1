#ifndef TUBESOOP_CARDS_HPP
#define TUBESOOP_CARDS_HPP
#include <string>
#include "hand.hpp"
#include "ability.hpp"

class Card : protected Hand {
public:
    virtual void print() = 0;

};

class PlayerCard : Card {
private:
    int number;
    Color color;
    std::map<Color, std::string> colorString = {
            {GREEN, "Hijau"},
            {BLUE, "Biru"},
            {YELLOW, "Kuning"},
            {RED, "Merah"}
    };
public:
    PlayerCard(int, Color);
    PlayerCard(const PlayerCard&);
    int getNumber() const;
    Color getColor();
    std::string getColorString();
    float getValue() override;
    void print() override;
    bool operator>(const PlayerCard&) const;
    bool operator<(const PlayerCard&) const;
    bool operator==(const PlayerCard&) const;
    bool operator!=(const PlayerCard&) const;
    bool operator>=(const PlayerCard&) const;
    bool operator<=(const PlayerCard&) const;
    friend std::ostream& operator<<(std::ostream&, PlayerCard);
};

class AbilityCard : Card {
private:
    Ability& ability;
    int abilityCardId;
    std::map<AbilityIds, std::string> abilityString = {
            {REROLL, "Reroll"},
            {DOUBLE, "Double"},
            {QUADRUPLE, "Quadruple"},
            {HALF, "Half"},
            {QUARTER, "Quarter"},
            {REVERSE, "Reverse"},
            {SWAPCARD, "Swap Card"},
            {SWITCH, "Switch"},
            {ABILITYLESS, "Abilityless"}
    };
public:
    explicit AbilityCard(Ability&);
    AbilityCard(const AbilityCard&);
    Ability& getAbility();
    float getValue() override;
    int getId() const;
    void print() override;
    void consume();
};

#endif
