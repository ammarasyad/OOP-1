#ifndef IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_GAMEIO_HPP
#define IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_GAMEIO_HPP
#include "cards.hpp"
#include "player.hpp"
#include "gamestate.hpp"
#include "ability.hpp"
#include <vector>

class GameIO {
    public:
        void startGame();

        void setAllPlayerName(GameState& game_state);

        int restartGame();

        void printEndGame(GameState& game_state);

        void getCommand(GameState& game_state);

        void printTableCard(GameState& game_state);

        void nextIO(GameState& game_state);

        void cantUseAbility();

        void reRollIO(GameState& game_state);

        void doubleIO(GameState& game_state);

        void quadrupleIO(GameState& game_state);

        void halfIO(GameState& game_state);

        void quarterIO(GameState& game_state);

        void reverseIO(GameState& game_state);
        void secondCommand(Player currentPlayer, GameState& game_state);
        void printQueue(std::vector<Player*> queue);

        void swapCardIO(GameState& game_state);
        int firstSwapTarget(Player player, std::vector<Player> player_list);
        int secondSwapTarget(Player player, int first_id, std::vector<Player> player_list);
        int firstSwapCard(Player first_player);
        int secondSwapCard(Player second_player);

        void switchIO(GameState& game_state);

        void abilitylessIO(GameState& game_state);
        bool checkNoAbilty(Player player, std::vector<Player> player_list);
        int targetAbilityless(Player player, std::vector<Player> player_list);
};


#endif //IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_GAMEIO_HPP
