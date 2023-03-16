#ifndef TABLE_CARDS_HPP
#define TABLE_CARDS_HPP

#include "limitedinventory.hpp"
#include "cards.hpp"


class TableCards : public InventoryHolder<LimitedInventory<PlayerCard>, PlayerCard>{
    private:
    public:
        TableCards();
        TableCards(LimitedInventory<PlayerCard>);

        LimitedInventory<PlayerCard> getInventory();
        void setInventory(LimitedInventory<PlayerCard>);

        void addItem(PlayerCard);
        void removeItem(PlayerCard);
        
        PlayerCard getItemAt(int);

        void reset();
};

#endif