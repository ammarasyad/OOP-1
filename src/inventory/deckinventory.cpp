#include "deckinventory.hpp"

DeckInventory::DeckInventory(): LimitedInventory(52) {

}

DeckInventory::DeckInventory(int limit): LimitedInventory(limit) {

}

void DeckInventory::shuffle() {
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(deck), std::end(deck), rng);
}

DeckInventory &DeckInventory::operator+=(const PlayerCard &card) {
    LimitedInventory::operator+=(card);
    return *this;
}

DeckInventory DeckInventory::operator+(const PlayerCard &card) const {
    DeckInventory temp = *this;
    return temp += card;
}

DeckInventory &DeckInventory::operator-=(const PlayerCard &card) {
    LimitedInventory::operator-=(card);
    return *this;
}

DeckInventory DeckInventory::operator-(const PlayerCard &card) const {
    DeckInventory temp = *this;
    return temp -= card;
}

DeckInventory operator+(PlayerCard &card, DeckInventory &inventory) {
    return inventory + card;
}

DeckInventory operator-(PlayerCard &card, DeckInventory &inventory) {
    return inventory - card;
}
