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


        void addCard(Card card);

        void clear();
};