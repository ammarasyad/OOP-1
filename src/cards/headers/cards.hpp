#ifndef TUBESOOP_CARDS_HPP
#define TUBESOOP_CARDS_HPP
#include <string>
#include "hand.hpp"
#include "ability.hpp" // Dummy header

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

template <class T>
class AbilityCard : Card {
private:
    Ability<T> ability;
public:
    explicit AbilityCard(Ability<T>);
    AbilityCard(const AbilityCard&);
    virtual ~AbilityCard();
    Ability<T> getAbility();
    void print() override;
    void consume();
};

#endif
