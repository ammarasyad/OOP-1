#include "gameio.hpp"
#include "gamestate.hpp"
#include "gamestatefactory.hpp"

int main() {
    // config
    int playerCount = 7;

    // end of config

    std::vector<Player> playerList;

    for (int i  = 0; i < playerCount; ++i) {
        playerList.emplace_back();
    }

    GameIO gameIo;
    GameState s(playerList);
    s.startGame();

    while(!s.isFinish()) {
        gameIo.startGame(s);
        gameIo.setAllPlayerName(s);
        gameIo.getCommand(s);
    }

}