#ifndef TUBESOOP_CARDS_HPP
#define TUBESOOP_CARDS_HPP
#include <string>
#include "hand.hpp"

class Card : public virtual Hand {
public:
    explicit Card(int, Color);
    Card(const Card& other);
    int getNumber() const;
    Color getColor();
    string getColorString();
    float getValue() override;
    bool operator>(const Card&) const;
    bool operator<(const Card&) const;
    bool operator==(const Card&) const;
    bool operator!=(const Card&) const;
    bool operator>=(const Card&) const;
    bool operator<=(const Card&) const;
protected:
    int number;
    Color color;
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
