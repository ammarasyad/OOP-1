#include "limitedinventory.hpp"
#include "generalexceptions.hpp"
#include <bits/stdc++.h>

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
void LimitedInventory<T>::removeFromDeck(T &card) {
    if (this->deckSize <= 0) {
        throw InventoryException("inventory is empty when trying to remove element");
    }

    auto it = std::find(this->deck.begin(), this->deck.end(), card);
    if (it == this->deck.end()) {
        throw InventoryException("card to delete not found");
    }

    this->deck.erase(it);
    this->deckSize -= 1;
}

template <class T>
LimitedInventory<T> &LimitedInventory<T>::operator+(T &card) {
    addToDeck(card);
    return *this;
}

template <class T>
LimitedInventory<T> &operator+(T &card, LimitedInventory<T> &inventory) {
    return inventory + card;
}

template <class T>
LimitedInventory<T> &LimitedInventory<T>::operator-(T &card) {
    this->removeFromDeck(card);
    return *this;
}

template <class T>
LimitedInventory<T> &operator-(T &card, LimitedInventory<T> &inventory) {
    return inventory - card;
}
