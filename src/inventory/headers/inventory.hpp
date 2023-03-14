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
        virtual std::vector<T>& operator+(T&) = 0;
};

#endif //IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_INVENTORY_HPP
