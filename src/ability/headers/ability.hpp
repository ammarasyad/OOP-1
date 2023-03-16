#ifndef IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_ABILITY_HPP
#define IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_ABILITY_HPP

#include "player.hpp"
#include "gamestate.hpp"

class GameState;

class Ability {
protected:
    GameState& state;
    explicit Ability(GameState& state);
    explicit Ability(GameState&& state) = delete;
    int abilityCardId = 0;
public:
    virtual void consume() = 0;
    int getId() const;
};

class ReRoll : public Ability {
public:
    explicit ReRoll(GameState&);
    explicit ReRoll(GameState&&) = delete;
    void consume() override;
};

class Double : public Ability {
public:
    explicit Double(GameState&);
    explicit Double(GameState&&) = delete;
    void consume() override;
};

class Quadruple : public Ability {
public:
    explicit Quadruple(GameState&);
    explicit Quadruple(GameState&&) = delete;
    void consume() override;
};

class Half : public Ability {
public:
    explicit Half(GameState&);
    explicit Half(GameState&&) = delete;
    void consume() override;
};

class Quarter : public Ability {
public:
    explicit Quarter(GameState&);
    explicit Quarter(GameState&&) = delete;
    void consume() override;
};

class Reverse : public Ability {
public:
    explicit Reverse(GameState&);
    explicit Reverse(GameState&&) = delete;
    void consume() override;
};

class SwapCard : public Ability {
private:
    int firstTargetId;
    int secondTargetId;
    int firstCard;
    int secondCard;
public:
    explicit SwapCard(GameState&);
    explicit SwapCard(GameState&&) = delete;
    void setTarget(int, int, int, int);
    void consume() override;
};

class Switch : public Ability {
private:
    int targetId;
public:
    explicit Switch(GameState&);
    explicit Switch(GameState&&) = delete;
    void setTarget(int);
    void consume() override;
};

class Abilityless : public Ability {
private:
    int targetId;
public:
    explicit Abilityless(GameState&);
    explicit Abilityless(GameState&&) = delete;
    void setTarget(int);
    void consume() override;
};

#endif 
