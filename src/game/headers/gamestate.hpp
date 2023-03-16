#ifndef IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_GAMESTATE_HPP
#define IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_GAMESTATE_HPP

class Player;
class DeckInventory;

#include <vector>
#include "player.hpp"
#include "deckCard.hpp"



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

        DeckCard* deck;

        int round;
        long long int gamePoint;

        void endRound();

        static int creationCount;

    public:
        GameState(std::vector<Player>&);
        GameState(std::vector<Player>&, DeckInventory&);

        long long int getPoint() const;
        int getRound() const;
        Player& getPlayerById(int);
        std::vector<Player>& getPlayerList();
        Player& getCurrentPlayer();
        std::vector<Player*>& getQueue();
        DeckCard& getDeck();
        std::vector<Player*>::iterator& getStartIterator();
        std::vector<int> getNextTurnIds();

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
