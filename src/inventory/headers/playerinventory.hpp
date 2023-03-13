#ifndef IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_PLAYERINVENTORY_HPP
#define IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_PLAYERINVENTORY_HPP

#include "limitedinventory.hpp"
#include "cards.hpp"

class PlayerInventory: LimitedInventory {
private:
    AbilityCard *abilityCard;
    bool abilityAvailable;
public:
    PlayerInventory();
    bool isAbilityAvailable() const;
    void setAbilityCard(AbilityCard&);
    void setAbilityUsed();
    void resetPlayer();

};

#endif //IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_PLAYERINVENTORY_HPP
