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
    inventory.addToDeck(card);
    return inventory;
}

template <class T>
LimitedInventory<T> &LimitedInventory<T>::operator-(T &card) {
    this->removeFromDeck(card);
    return *this;
}

template <class T>
LimitedInventory<T> &operator-(T &card, LimitedInventory<T> &inventory) {
    inventory.removeFromDeck(card);
    return inventory;
}

template<class T>
std::pair<std::vector<T> &, std::vector<T> &>
LimitedInventory<T>::switchCards(std::vector<T> &inv1, std::vector<T> &inv2, std::vector<std::pair<int, int>> &indices) {
    for (auto it = indices.begin(); it != indices.end(); ++it) {
        std::pair<int, int> cPair = *it;
        T temp = inv1.at(cPair.first);
        inv1.at(cPair.first) = inv2.at(cPair.second);
        inv2.at(cPair.second) = temp;
    }

    return std::make_pair(inv1, inv2);
}
