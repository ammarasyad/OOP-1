#include <iostream>
#include "cards.hpp"
#include "hand.hpp"
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

std::string PlayerCard::getColorString() {
    return colorString[this->color];
}

float PlayerCard::getValue() {
    return (float) (this->number + this->color * 0.3);
}

void PlayerCard::print() {
    std::cout << this->number << " " << this->getColorString() << std::endl;
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
std::ostream& operator<<(std::ostream& os, PlayerCard card) {
    os << card.getNumber() << " " << card.getColorString();
    return os;
}

/** Ability Card **/
AbilityCard::AbilityCard(Ability& ability) : ability(ability) {
    this->abilityCardId = ability.getId();
}

AbilityCard::AbilityCard(const AbilityCard &other) : AbilityCard(other.ability) {}

Ability& AbilityCard::getAbility() {
    return this->ability;
}

float AbilityCard::getValue() {
    return (float) this->getId();
}

int AbilityCard::getId() const {
    return this->abilityCardId;
}

void AbilityCard::print() {
    std::cout << this->abilityString[this->abilityCardId] << std::endl;
}

void AbilityCard::consume() {
    this->ability.consume();
}