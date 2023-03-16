#ifndef DECK_INVEN_HPP
#define DECK_INVEN_HPP

#include "cards.hpp"
#include "limitedinventory.hpp"
#include <algorithm>
#include <random>

class DeckInventory: public LimitedInventory<PlayerCard> {
private:
    int limit;
public:
    DeckInventory();
    void shuffle();

    DeckInventory operator+(const PlayerCard& card) const;
    DeckInventory operator-(const PlayerCard& card) const;

    virtual DeckInventory& operator+=(const PlayerCard& card) override;
    virtual DeckInventory& operator-=(const PlayerCard& card) override;

    friend DeckInventory operator+(PlayerCard&, DeckInventory&);
    friend DeckInventory operator-(PlayerCard&, DeckInventory&);


};

#endif