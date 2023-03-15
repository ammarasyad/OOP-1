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
        bool abilityLess_;

    public:
        Player();
        explicit Player(PlayerInventory deck);
//-----------------------------------------------
        PlayerInventory getInventory() const;
        void setInventory(PlayerInventory);

        void addItem(PlayerCard);
        void removeItem(PlayerCard);

        void setAbilityCard(AbilityCard&);
        bool useAbilityCard(AbilityCard&);
        
        PlayerCard getItemAt(int) const;
        void reset();
//-----------------------------------------------
        int getPlayerId() const;

        int getPoint() const;
        void setPoint(int);
        void addPoint(int);

        float getHandScore() const;
        void setHandScore(float);

        bool haveUsedCommand() const;
        void canUseCommand();
        void cantUseCommand();

        void setAbilityLess();
        bool isAbilityLess();

        //operator
        bool operator<(const Player&) const;
        bool operator>(const Player&) const;
        bool operator==(const Player&) const;

};

#endif //IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_PLAYER_HPP
