#ifndef DECK_CARD_HPP
#define DECK_CARD_HPP

#include "inventoryHolder.hpp"
#include "deckinventory.hpp"
#include "cards.hpp"

class DeckCard : public InventoryHolder<DeckInventory, PlayerCard> {
    public:
        DeckCard();
        DeckCard(DeckInventory inventory);
        DeckInventory getInventory() const override;
        void setInventory(DeckInventory) override;

        void addItem(const PlayerCard&) override;
        void removeItem(const PlayerCard&) override;
        
        PlayerCard getItemAt(const int&) const override;
        PlayerCard drawACard();

        void shuffle();

        void reset() override;
};

#endif