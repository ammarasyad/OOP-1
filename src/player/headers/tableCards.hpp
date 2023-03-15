#include "limitedinventory.hpp"
#include "cards.hpp"

//temp
class Deck {
    public:
        void show();
};


class TableCards : public InventoryHolder<LimitedInventory<PlayerCard>, PlayerCard>{
    private:
    public:
        LimitedInventory<PlayerCard> getInventory();
        void setInventory(LimitedInventory<PlayerCard>);

        void addItem(PlayerCard);
        void removeItem(PlayerCard);
        
        PlayerCard getItemAt(int);
};