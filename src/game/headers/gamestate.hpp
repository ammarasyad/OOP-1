#ifndef IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_GAMESTATE_HPP
#define IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_GAMESTATE_HPP

#include <vector>
#include "player.hpp"

// TODO: tidy up
class GameState {
    private:
        std::vector<Player*> queue;
        std::vector<Player> playerList;
        std::vector<Player*>::iterator currentStart;
        std::vector<Player*>::iterator currentEnd;
        int firstTurnId;
        int round;
        long long int gamePoint;
        inline void reverseQueue();
        void endRound();

    public:
        GameState(std::vector<Player>&);
        long long int getPoint() const;
        int getRound() const;
        Player& getPlayer(int);
        Player& getCurrentPlayer();
        std::vector<Player*>& getQueue();
        Player& nextTurn(char);
        void multiplyPoint(int);
        void dividePoint(int);
        void startGame();
        void restartGame();
        void print();
};

#endif //IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_GAMESTATE_HPP
