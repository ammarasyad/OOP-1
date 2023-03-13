#include "inventoryHolder.hpp"
#include "cards.hpp"

//temp
class Deck {
    public:
        void show();
};


class TableCards : InventoryHolder{
    private:
        Deck tableCards_;
    public:
        TableCards();
        TableCards(Deck TableCards);

        void showInventory() override;

        void addCard(Card card);

        void clear();
};