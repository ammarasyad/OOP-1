#ifndef IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_INVENTORY_HPP
#define IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_INVENTORY_HPP

#include <vector>

#include "inventory.hpp"
#include "generalexceptions.hpp"

template <class T>
class Inventory {
    protected:
        std::vector<T> deck;
        int deckSize;
    public:
        Inventory();
        virtual ~Inventory();

        virtual void addToDeck(T&);
        T& at(int) const;
        int getDeckSize() const;
        std::vector<T> &getDeck();

        /*
         * this function switch elements between vector v1 and v2 with index indices[i][0] (v1) and index
         * indices[i][1] (v2)
         *
         * */
        static void
        switchElements(Inventory<T> &inv1, Inventory<T> &inv2, std::vector<std::pair<int, int>> &indices);

        virtual bool operator==(const Inventory<T>&) const;

};

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
std::vector<T> &Inventory<T>::getDeck() {
    return deck;
}
#include <iostream>

template<class T>
void
Inventory<T>::switchElements(Inventory<T> &inv1, Inventory<T> &inv2, std::vector<std::pair<int, int>> &indices) {
    std::vector<T> &v1 = inv1.deck, &v2 = inv2.deck;

    for (auto it = indices.begin(); it != indices.end(); ++it) {
        std::pair<int, int> cPair = *it;
        std::swap(v1[cPair.first], v2[cPair.second]);
    }
}

template<class T>
bool Inventory<T>::operator==(const Inventory<T> &comp) const{
    if (this->deckSize != comp.deckSize)
        return false;

    for (auto el1 = this->deck.begin(), el2 = comp.deck.begin();
         el1 != this->deck.end(), el2 != comp.deck.end();
         ++el1, ++el2) {

        if (*el1 != *el2)
            return false;

    }
    return true;
}

#endif //IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_INVENTORY_HPP
