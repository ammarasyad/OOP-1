#ifndef IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_GAMESTATE_HPP
#define IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_GAMESTATE_HPP

#include <vector>
#include "player.hpp"

class GameState {
    /*
     * this class have methods that could break the game, such as reversing queue, multiply points, etc.
     * therefore, GameState object must be called only from the classes implementing the players' constraint.
     *
     * this class MUST be a singleton, we'd give a warning when GameState is created more than once.
     * */
    private:
        std::vector<Player*> queue;
        std::vector<Player> &playerList;

        std::vector<Player*>::iterator currentStart;
        std::vector<Player*>::iterator currentEnd;

        int round;
        long long int gamePoint;

        void endRound();

        static int creationCount;

    public:
        GameState(std::vector<Player>&);

        long long int getPoint() const;
        int getRound() const;
        Player& getPlayerById(int);
        std::vector<Player>& getPlayerList();
        Player& getCurrentPlayer();
        std::vector<Player*>& getQueue();
        std::vector<Player*>::iterator& getStartIterator();
        std::vector<int> getNextTurnIds();

        /*
         * char param is used to decide whether to reverse the queue (using the reverse ability) or not
         * value y or Y will reverse the queue, else keep the order
         *
         * @return player current turn
         */
        Player& nextTurn();

        void reverseQueue();
        void multiplyPoint(int);
        void dividePoint(int);

        void startGame();
        void restartGame();
        // print is for debugging purposes only !!!
        void print();
};

#endif //IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_GAMESTATE_HPP
