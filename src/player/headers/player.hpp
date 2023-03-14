#ifndef IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_PLAYER_HPP
#define IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_PLAYER_HPP

#include "inventoryHolder.hpp"


// TODO: dummy class, please change later
class Player : public InventoryHolder<Card> {
    private:
        static int PLAYER_AMOUNT;
        const int playerId_;
        int point_;
        
        
    public:
        Player();
        Player(PlayerInventory deck);

        virtual Inventory<Card> getInventory();
        virtual void setInventory(Inventory<Card>);

        virtual void addItem(Card);
        virtual void removeIten(Card);
        
        virtual Card getItemAt(int);

        int getId();

        int getPoint();
        void setPoint(int);
        void addPoint(int);

};

#endif //IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_PLAYER_HPP
