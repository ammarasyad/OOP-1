#ifndef IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_GAMESTATEFACTORY_HPP
#define IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_GAMESTATEFACTORY_HPP

#include "gamestate.hpp"

class GameStateFactory {
private:
    GameState& gameState;
public:
    GameStateFactory(std::vector<Player>& playerList): gameState(*new GameState(playerList)) {
    }

    GameState& getGameState() {
        return gameState;
    }
};

#endif //IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_GAMESTATEFACTORY_HPP
