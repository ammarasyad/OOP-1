#include <iostream>
#include "headers/cards.hpp"
#include "headers/hand.hpp"
#include "generalexceptions.hpp"

/** Player Card **/

PlayerCard::PlayerCard(int number, Color color) : color(color) {
    if (number < 1 || number > 13) {
        throw GameStateException("Kartu harus memiliki nomor di antara 1-13");
    }
    this->number = number;
}

PlayerCard::PlayerCard(const PlayerCard &other) : PlayerCard(other.number, other.color) {}

int PlayerCard::getNumber() const {
    return this->number;
}

Color PlayerCard::getColor() {
    return this->color;
}

string PlayerCard::getColorString() {
    return colorString[this->color];
}

float PlayerCard::getValue() {
    return (float) (this->number + this->color * 0.3);
}

void PlayerCard::print() {
    cout << this->number << " " << this->getColorString() << endl;
}

bool PlayerCard::operator<(const PlayerCard &other) const {
    return this->number < other.number || (this->number == other.number && this->color < other.color);
}

bool PlayerCard::operator>(const PlayerCard &other) const {
    return this->number > other.number || (this->number == other.number && this->color > other.color);
}

bool PlayerCard::operator==(const PlayerCard &other) const {
    return this->number == other.number && this->color == other.color;
}

bool PlayerCard::operator!=(const PlayerCard &other) const {
    return !(*this == other);
}

bool PlayerCard::operator>=(const PlayerCard &other) const {
    return *this > other || *this == other;
}

bool PlayerCard::operator<=(const PlayerCard &other) const {
    return *this < other || *this == other;
}

// A bit redundant, but it's okay I guess
ostream& operator<<(ostream& os, PlayerCard card) {
    os << card.getNumber() << " " << card.getColorString();
    return os;
}

/** Ability Card **/
template <class T>
AbilityCard<T>::AbilityCard(Ability<T> ability) : ability(ability) {}

template <class T>
AbilityCard<T>::AbilityCard(const AbilityCard<T> &other) : AbilityCard(other.ability) {}

template <class T>
AbilityCard<T>::~AbilityCard() = default;

template <class T>
Ability<T> AbilityCard<T>::getAbility() {
    return this->ability;
}
template <class T>
void AbilityCard<T>::print() {
    cout << this->ability.toString() << endl;
}

// TODO: Implement effects
template <class T>
void AbilityCard<T>::consume() {
    this->ability.consume();
}