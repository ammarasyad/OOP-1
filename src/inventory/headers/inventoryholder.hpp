#ifndef IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_INVENTORYHOLDER_HPP
#define IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_INVENTORYHOLDER_HPP

#include <vector>
#include "cards.hpp"

class InventoryHolder {
    protected:
        std::vector<PlayerCard> deck;
        int deckSize;
    public:
        InventoryHolder();
        virtual void addToDeck(PlayerCard&) = 0;
        virtual std::vector<PlayerCard>& operator+(PlayerCard&) = 0;
};

#endif //IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_INVENTORYHOLDER_HPP
