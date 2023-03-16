#ifndef TABLE_CARDS_HPP
#define TABLE_CARDS_HPP

#include "limitedinventory.hpp"
#include "cards.hpp"


class TableCards : public InventoryHolder<LimitedInventory<PlayerCard>, PlayerCard>{
    private:
    public:
        TableCards();
        TableCards(LimitedInventory<PlayerCard>);

        LimitedInventory<PlayerCard> getInventory() const override;
        void setInventory(LimitedInventory<PlayerCard>) override;

        void addItem(PlayerCard) override;
        void removeItem(const PlayerCard&) override;
        
        PlayerCard getItemAt(const int&) const override;

        void reset() override;
};

#endif