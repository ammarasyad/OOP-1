#ifndef IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_PLAYER_HPP
#define IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_PLAYER_HPP

#include "cards.hpp"
#include "inventoryHolder.hpp"
#include "playerinventory.hpp"


// TODO: dummy class, please change later
class Player : public InventoryHolder<PlayerInventory,PlayerCard> {
    private:
        static int PLAYER_AMOUNT;
        const int playerId_;
        int point_;

        float handScore_;
        
        bool usedCommand_;

    public:
        Player();
        explicit Player(PlayerInventory deck);

        PlayerInventory getInventory();
        void setInventory(PlayerInventory);

        void addItem(PlayerCard);
        void removeItem(PlayerCard);
        
        PlayerCard getItemAt(int);

        int getPlayerId();

        int getPoint();
        void setPoint(int);
        void addPoint(int);

        float getHandScore();
        void setHandScore(float);

        bool haveUsedCommand();
        void canUseCommand();
        void cantUseCommand();

        //operator
        bool operator<(Player);
        bool operator>(Player);
        bool operator==(Player);

};

#endif //IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_PLAYER_HPP
