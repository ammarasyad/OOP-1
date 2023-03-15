#ifndef IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_INVENTORY_HPP
#define IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_INVENTORY_HPP

#include <vector>
#include "cards.hpp"

template <class T>
class Inventory {
    protected:
        std::vector<T> deck;
        int deckSize;
    public:
        Inventory();
        virtual void addToDeck(T&) = 0;
        T& at(int) const;
        int getDeckSize() const;
};

#endif //IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_INVENTORY_HPP
