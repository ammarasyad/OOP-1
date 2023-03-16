#ifndef IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_PLAYER_HPP
#define IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_PLAYER_HPP

class PlayerCard;
class AbilityCard;
class PlayerInventory;
template <class T, class U>
class InventoryHolder;
class DeckInventory;
class DeckCard;

#include "deckCard.hpp"
#include "deckinventory.hpp"
#include "cards.hpp"
#include "inventoryHolder.hpp"
#include "playerinventory.hpp"

class Player : public InventoryHolder<PlayerInventory, PlayerCard> {
    private:
        std::string name_;

        static int PLAYER_AMOUNT;
        const int playerId_;
        int point_;
        
        bool usedCommand_;
        bool abilityLess_;

    public:
        Player();
        explicit Player(std::string name);
        explicit Player(PlayerInventory deck);
        explicit Player(PlayerInventory deck, std::string name);

//-----------------------------------------------
        PlayerInventory getInventory() const;
        void setInventory(PlayerInventory);

        void addItem(const PlayerCard&);
        void removeItem(const PlayerCard&);

        void setAbilityCard(const AbilityCard&);
        bool useAbilityCard(const AbilityCard&);
        
        PlayerCard getItemAt(const int&);
        void reset();

        void resetHand();
//-----------------------------------------------
        int getPlayerId() const;

        int getPoint() const;
        void setPoint(int);
        void addPoint(int);

        bool haveUsedCommand() const;
        void canUseCommand();
        void cantUseCommand();

        void setAbilityLess();
        bool isAbilityLess();

        void setName(std::string);
        std::string getName() const;

        //operator
        Player& operator=(const Player&);

        bool operator<(const Player&) const;
        bool operator>(const Player&) const;
        bool operator==(const Player&) const;

};

#endif //IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_PLAYER_HPP
