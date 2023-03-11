#include "cards.hpp"
#include "hand.hpp"

Card::Card(int number, Color color) : number(number), color(color) {}

float Card::value() const {
    return (float)(this->number + this->color * 0.3);
}

//int Card::getNumber() const {
//    return this->number;
//}
//
//string Card::getColor() {
//    return colorToString(this->color);
//}

bool Card::operator<(Card& card) {
    return this->number < card.number || (this-> number == card.number && this->color < card.color);
}

bool Card::operator>(Card& card) {
    return this->number > card.number || (this-> number == card.number && this->color > card.color);
}

bool Card::operator==(Card& card) {
    return this->number == card.number && this->color == card.color;
}

bool Card::operator!=(Card& card) {
    return !(*this == card);
}

bool Card::operator>=(Card& card) {
    return *this > card || *this == card;
}

bool Card::operator<=(Card& card) {
    return *this < card || *this == card;
}

PlayerCard::PlayerCard(int number, Color color) : Card(number, color) {}

AbilityCard::AbilityCard(int number, Color color) : Card(number, color) {}