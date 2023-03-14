#ifndef IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_ABILITY_HPP
#define IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_ABILITY_HPP

#include "gamestate.hpp"
#include "player.hpp"

enum AbilityIds {
    REROLL = 1,
    DOUBLE = 2,
    QUADRUPLE = 3,
    HALF = 4,
    QUARTER = 5,
    REVERSE = 6,
    SWAPCARD = 7,
    SWITCH = 8,
    ABILITYLESS = 9
};

class Ability {
protected:
    GameState& state;
    explicit Ability(GameState& state);
    int abilityCardId = 0;
public:
    virtual void consume() = 0;
    int getId() const;
};

class ReRoll : public Ability {
public:
    explicit ReRoll(GameState&);
    void consume() override;
};

class Double : public Ability {
public:
    explicit Double(GameState&);
    void consume() override;
};

class Quadruple : public Ability {
public:
    explicit Quadruple(GameState&);
    void consume() override;
};

class Half : public Ability {
public:
    explicit Half(GameState&);
    void consume() override;
};

class Quarter : public Ability {
public:
    explicit Quarter(GameState&);
    void consume() override;
};

class Reverse : public Ability {
public:
    explicit Reverse(GameState&);
    void consume() override;
};

class SwapCard : public Ability {
public:
    explicit SwapCard(GameState&);
    void consume() override;
};

class Switch : public Ability {
public:
    explicit Switch(GameState&);
    void consume() override;
};

class Abilityless : public Ability {
public:
    explicit Abilityless(GameState&);
    void consume() override;
};

#endif 
