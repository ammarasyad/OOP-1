#include "inventory.hpp"
#include "generalexceptions.hpp"

template <class T>
Inventory<T>::Inventory(): deckSize(0) {

}

template <class T>
T& Inventory<T>::at(int index) {
    if (index >= deckSize) {
        throw InventoryException("index entered is bigger than the actual size on function Inventory::at()");
    }
    return deck.at(index);
}

template <class T>
int Inventory<T>::getDeckSize() {
    return deckSize;
}