#include "inventory.hpp"
#include "generalexceptions.hpp"

template <class T>
Inventory<T>::Inventory(): deckSize(0) {

}

template <class T>
void Inventory<T>::addToDeck(T &card) {
    this->deck.push_back(card);
    this->deckSize += 1;
}

template <class T>
T& Inventory<T>::at(int index) const{
    if (index >= deckSize) {
        throw InventoryException("index entered is bigger than the actual size on function Inventory::at()");
    }
    return deck.at(index);
}

template <class T>
int Inventory<T>::getDeckSize() const{
    return deckSize;
}

template<class T>
void
Inventory<T>::switchElements(Inventory<T> &inv1, Inventory<T> &inv2, std::vector<std::pair<int, int>> &indices) {
    std::vector<T> &v1 = inv1.deck, &v2 = inv2.deck;

    for (auto it = indices.begin(); it != indices.end(); ++it) {
        std::pair<int, int> cPair = *it;
        T temp = v1.at(cPair.first);
        v1.at(cPair.first) = v2.at(cPair.second);
        v1.at(cPair.second) = temp;
    }
}

template<class T>
bool Inventory<T>::operator==(Inventory<T> &comp) {
    if (this->deckSize != comp)
        return false;

    for (auto el1 = this->deck.begin(), el2 = comp.deck.begin();
            el1 != this->deck.end(), el2 != comp.deck.end();
            ++el1, ++el2) {

        if (*el1 != *el2)
            return false;

    }
    return true;
}