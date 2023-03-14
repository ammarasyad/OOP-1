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
AbilityCard::AbilityCard(Ability& ability) : ability(ability) {
    this->abilityCardId = ability.getId();
}

Ability& AbilityCard::getAbility() {
    return this->ability;
}

int AbilityCard::getId() const {
    return this->abilityCardId;
}

void AbilityCard::print() {

}

void AbilityCard::consume() {
    this->ability.consume();
}