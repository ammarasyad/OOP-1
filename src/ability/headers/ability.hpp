#ifndef IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_ABILITY_HPP
#define IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_ABILITY_HPP
#include "gamestate.hpp"
#include "player.hpp"

class Ability : public GameState{
    public:
        virtual void consume() = 0;
};

class ReRoll : public Ability {
    public:
        void consume();
};

class Double : public Ability {
    public:
        void consume();
};

class Quadruple : public Ability {
    public:
        void consume();
};

class Half : public Ability {
    public:
        void consume();
};

class Quarter : public Ability {
    public:
        void consume();
};

class Reverse : public Ability {
    public:
        void consume();
};

class SwapCard : public Ability {
    public:
        void consume();
};

class Switch : public Ability {
    public:
        void consume();
};

class Abilityless : public Ability {
    public:
        void consume();
};

#endif 
