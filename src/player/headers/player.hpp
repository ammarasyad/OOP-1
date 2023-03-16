#ifndef IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_PLAYER_HPP
#define IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_PLAYER_HPP

#include "cards.hpp"
#include "inventoryHolder.hpp"
#include "playerinventory.hpp"


// TODO: dummy class, please change later
class Player : public InventoryHolder<PlayerInventory,PlayerCard> {
    private:
        std::string name_;

        static int PLAYER_AMOUNT;
        const int playerId_;
        int point_;

        float handScore_;
        
        bool usedCommand_;
        bool abilityLess_;

    public:
        Player();
        explicit Player(std::string name);
        explicit Player(PlayerInventory deck);
        explicit Player(PlayerInventory deck, std::string name);

//-----------------------------------------------
        PlayerInventory getInventory() const override;
        void setInventory(PlayerInventory) override;

        void addItem(const PlayerCard&) override;
        void removeItem(const PlayerCard&) override;

        void setAbilityCard(const AbilityCard&);
        bool useAbilityCard(const AbilityCard&);
        
        PlayerCard getItemAt(const int&) const override;
        void reset() override;
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

        void setName(std::string);
        std::string getName() const;

        //operator
        bool operator<(const Player&) const;
        bool operator>(const Player&) const;
        bool operator==(const Player&) const;

};

#endif //IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_PLAYER_HPP
