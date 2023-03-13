#include <iostream>
#include "headers/cards.hpp"
#include "headers/hand.hpp"
#include "generalexceptions.hpp"

/** Player Card **/

PlayerCard::PlayerCard(int number, Color color) : color(color) {
    if (this->number < 1 || this->number > 13) {
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

/** Ability Card **/

AbilityCard::AbilityCard(Ability ability) : ability(ability) {}

AbilityCard::AbilityCard(const AbilityCard &other) : AbilityCard(other.ability) {}

AbilityCard::~AbilityCard() = default;

Ability AbilityCard::getAbility() {
    return this->ability;
}

void AbilityCard::print() {
    cout << abilityString[this->ability] << endl;
}

// TODO: Implement effects
void AbilityCard::consume() {
    switch (this->ability) {
        case REROLL:
            break;
        case QUADRUPLE:
            break;
        case QUARTER:
            break;
        case REVERSE_DIRECTION:
            break;
        case SWAP:
            break;
        case SWITCH:
            break;
        case ABILITYLESS:
            break;
    }
    delete this;
}