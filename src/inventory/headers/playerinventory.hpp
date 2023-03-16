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
    PlayerInventory(const PlayerInventory& other);
    ~PlayerInventory();

    bool isAbilityAvailable() const;
    bool isAbilityMatch(const AbilityCard &card);
    bool checkAbilityMatchAndUse(const AbilityCard &card);
    void setAbilityCard(const AbilityCard&);
    void setAbilityUsed();

    PlayerInventory& operator+=(const PlayerCard& card) override;
    PlayerInventory operator+(const PlayerCard& card) const;
    friend PlayerInventory operator+(const PlayerCard&, const PlayerInventory&);
    PlayerInventory& operator-=(const PlayerCard& card) override;
    PlayerInventory operator-(const PlayerCard& card) const;
    friend PlayerInventory operator-(const PlayerCard&, const PlayerInventory&);

    PlayerInventory& operator=(PlayerInventory&);

    void resetPlayer();

};

#endif //IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_PLAYERINVENTORY_HPP
