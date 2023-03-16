#ifndef DECK_CARD_HPP
#define DECK_CARD_HPP

#include "inventoryHolder.hpp"
#include "cards.hpp"

class DeckCard : public InventoryHolder<LimitedInventory<PlayerCard>, PlayerCard> {
    public:
        DeckCard();
        DeckCard(LimitedInventory<PlayerCard> inventory);
        LimitedInventory<PlayerCard> getInventory() const override;
        void setInventory(LimitedInventory<PlayerCard>) override;

        void addItem(PlayerCard) override;
        void removeItem(const PlayerCard&) override;
        
        PlayerCard getItemAt(const int&) const override;
        PlayerCard drawACard();

        void reset() override;
};

#endif