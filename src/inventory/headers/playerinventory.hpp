#ifndef IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_PLAYERINVENTORY_HPP
#define IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_PLAYERINVENTORY_HPP

#include "limitedinventory.hpp"
#include "cards.hpp"

class PlayerInventory: public LimitedInventory<PlayerCard> {
private:
    AbilityCard *abilityCard;
    bool abilityAvailable;
public:
    PlayerInventory();

    bool isAbilityAvailable() const;
    bool isAbilityMatch(AbilityCard &card);
    bool checkAbilityMatchAndUse(AbilityCard &card);
    void setAbilityCard(AbilityCard&);
    void setAbilityUsed();

    PlayerInventory& operator+(PlayerCard& card) override;
    friend PlayerInventory& operator+(PlayerCard&, PlayerInventory&);
    PlayerInventory& operator-(PlayerCard& card) override;
    friend PlayerInventory& operator-(PlayerCard&, PlayerInventory&);

    void resetPlayer();

};

#endif //IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_PLAYERINVENTORY_HPP
