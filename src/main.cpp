#include "gameio.hpp"
#include "gamestate.hpp"
#include "gamestatefactory.hpp"
#include "combo.hpp"

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

    gameIo.startGame();
    gameIo.setAllPlayerName(s);

    while(!s.isFinish()) {
        if (s.getRound() == 2) {
            // shuffle ability cards
        }
        for (int i = 0; i < 7; ++i) {
            gameIo.getCommand(s);
        }
        std::vector<Combination> combinations;
        for (int i = 0; i< 7; ++i) {
            Combination a(s.getPlayerById(i).getInventory().getDeck());
            combinations.push_back(a);
        }
        Combination maxC = Util::max<Combination>(combinations);
        Player p;
        for (int i = 0; i< 7; ++i) {
            if (maxC == combinations.at(i)) {
                s.getPlayerById(i).setPoint(s.getPlayerById(i)+s.getPoint());
            }
        }
    }

}