#include "limitedinventory.hpp"
#include "generalexceptions.hpp"

template <class T>
LimitedInventory<T>::LimitedInventory(): limit(100) {
}

template <class T>
LimitedInventory<T>::LimitedInventory(int limit): limit(limit) {
    if (limit <= 0)
        throw InventoryException("invalid inventory limit");

    if (limit < 30) {
        this->deck.reserve(limit);
    } else {
        this->deck.reserve(30 + 0.2*limit);
    }
}

template <class T>
void LimitedInventory<T>::addToDeck(T &card) {
    if (this->deckSize >= limit) {
        throw InventoryException("inventory limit exceeded");
    }
    this->deck.push_back(card);
    this->deckSize += 1;
}

template <class T>
std::vector<T> &LimitedInventory<T>::operator+(T &card) {
    addToDeck(card);
    return this->deck;
}

template <class T>
vector<T> &operator+(T &card, LimitedInventory<T> &inventory) {
    inventory.addToDeck(card);
    return inventory.deck;
}
