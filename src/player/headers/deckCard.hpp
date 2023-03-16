#ifndef DECK_CARD_HPP
#define DECK_CARD_HPP

#include "cards.hpp"
#include "inventoryHolder.hpp"
#include "deckinventory.hpp"

class PlayerCard;
class DeckInventory;
template <class T, class U>
class InventoryHolder;

class DeckCard : public InventoryHolder<DeckInventory, PlayerCard> {
    public:
        DeckCard();
        DeckCard(DeckInventory& inventory);
        DeckInventory getInventory() const override;
        void setInventory(DeckInventory) override;

        void addItem(const PlayerCard&) override;
        void removeItem(const PlayerCard&) override;
        
        PlayerCard getItemAt(const int&) override;
        PlayerCard drawACard();

        void shuffle();

        void reset() override;
};

#endif