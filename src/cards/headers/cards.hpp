#ifndef TUBESOOP_CARDS_HPP
#define TUBESOOP_CARDS_HPP
#include <string>
#include "hand.hpp"
#include "../ability/headers/ability.hpp"

class Card : protected Hand {
public:
    virtual void print() = 0;
protected:
    map<Color, string> colorString = {
            {GREEN, "Hijau"},
            {BLUE, "Biru"},
            {YELLOW, "Kuning"},
            {RED, "Merah"}
    };
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
    friend ostream& operator<<(ostream&, PlayerCard);
};

class AbilityCard : Card {
private:
    Ability& ability;
    int abilityCardId;
public:
    explicit AbilityCard(Ability&);
    Ability& getAbility();
    int getId() const;
    void print() override;
    void consume();
};

#endif
