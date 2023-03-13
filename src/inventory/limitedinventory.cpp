#include "limitedinventory.hpp"
#include "generalexceptions.hpp"

LimitedInventory::LimitedInventory(): limit(100) {
}

LimitedInventory::LimitedInventory(int limit): limit(limit) {
    if (limit <= 0)
        throw InventoryException("invalid inventory limit");

    if (limit < 30) {
        deck.reserve(limit);
    } else {
        deck.reserve(30 + 0.2*limit);
    }
}

void LimitedInventory::addToDeck(PlayerCard &card) {
    deck.push_back(card);
    deckSize += 1;
}

std::vector<PlayerCard> &LimitedInventory::operator+(PlayerCard &card) {
    addToDeck(card);
    return deck;
}

vector<PlayerCard> &operator+(PlayerCard &card, LimitedInventory& inventory) {
    inventory.addToDeck(card);
    return inventory.deck;
}
