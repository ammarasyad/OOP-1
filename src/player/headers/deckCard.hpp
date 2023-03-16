#ifndef DECK_CARD_HPP
#define DECK_CARD_HPP

#include "inventoryHolder.hpp"
#include "cards.hpp"

class DeckCard : public InventoryHolder<LimitedInventory<PlayerCard>, PlayerCard> {
    public:
        virtual LimitedInventory<PlayerCard> getInventory();
        virtual void setInventory(LimitedInventory<PlayerCard>);

        virtual void addItem(PlayerCard);
        virtual void removeItem(PlayerCard);
        
        virtual PlayerCard getItemAt(int);

        virtual void reset();
};

#endif