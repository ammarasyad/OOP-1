#include "headers/cards.hpp"
#include "headers/hand.hpp"

Card::Card(int number, Color color) : number(number), color(color) {}

Card::Card(const Card &other) : Card(other.number, other.color) {}

float Card::getValue() {
    return (float) (this->number + this->color * 0.3);
}

int Card::getNumber() const {
    return this->number;
}

Color Card::getColor() {
    return this->color;
}

string Card::getColorString() {
    return colorToString(this->color);
}

bool Card::operator<(const Card &card) const {
    return this->number < card.number || (this->number == card.number && this->color < card.color);
}

bool Card::operator>(const Card &card) const {
    return this->number > card.number || (this->number == card.number && this->color > card.color);
}

bool Card::operator==(const Card &card) const {
    return this->number == card.number && this->color == card.color;
}

bool Card::operator!=(const Card &card) const {
    return !(*this == card);
}

bool Card::operator>=(const Card &card) const {
    return *this > card || *this == card;
}

bool Card::operator<=(const Card &card) const {
    return *this < card || *this == card;
}

PlayerCard::PlayerCard(int number, Color color) : Card(number, color) {}

AbilityCard::AbilityCard(int number, Color color) : Card(number, color) {}