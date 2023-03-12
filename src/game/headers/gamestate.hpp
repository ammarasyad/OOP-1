#ifndef IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_GAMESTATE_HPP
#define IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_GAMESTATE_HPP

#include <vector>
#include "player.hpp"

// TODO: tidy up
class GameState {
private:
    std::vector<Player*> queue;
    std::vector<Player> player_list;
    std::vector<Player*>::iterator current_start;
    std::vector<Player*>::iterator current_end;
    int round;
    long long int point;

public:
    GameState(std::vector<Player>);
    long long int get_point() const;
    Player& get_player(int player_id);
    Player& get_current_player();
    std::vector<Player*>& get_queue();
    Player& next_player();
    void multiply_point(int multiplier);
    // reverse queue and automatically end the turn
    // should be called by the ability handler, NOT the main program
    void reverse_queue();
    void end_round();
    void start_game();
    void restart_game();
    void print();
};

#endif //IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_GAMESTATE_HPP
