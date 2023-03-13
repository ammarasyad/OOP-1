#ifndef IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_PLAYER_HPP
#define IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_PLAYER_HPP

#include "inventoryHolder.hpp"
#include "cards.hpp"
#include <iostream>

//temp
class Deck {
    public:
        void show();
};

// TODO: dummy class, please change later
class Player : InventoryHolder {
    private:
        static int PLAYER_AMOUNT;
        const int playerId_;
        int point_;
        Deck hand_;
        
    public:
        Player();
        Player(Deck deck);

        void showInventory() override;
        int getPoint();
        void setPoint(int point);
        void addPoint(int amount);

        Deck getHand();
        void setHand(Deck hand);

        void addCard(Card card);
        void removeCard(Card card);
        
        Card getCardAt(int index);

};

#endif //IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_PLAYER_HPP
