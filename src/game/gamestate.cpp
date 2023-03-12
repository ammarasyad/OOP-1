#include "gamestate.hpp"
#include "generalexceptions.hpp"
#include <bits/stdc++.h>

GameState::GameState(std::vector<Player> player_list): player_list(player_list), point(0), round(0) {

}

long long int GameState::get_point() const {
    return point;
}

Player& GameState::get_player(int player_id) {
    if (player_id > 7 || player_id <= 0) {
        throw GameStateException("player id does not exist");
    }
    return player_list.at(player_id);
}

Player &GameState::get_current_player() {
    return **current_start;
}


std::vector<Player*>& GameState::get_queue() {
    if (round == 0) {
        throw GameStateException("invalid operation on round-0");
    }
    return queue;
}

Player& GameState::next_player() {
    // check if all players already in the next round's queue
    if (current_start == current_end) {
        throw GameStateException("last player had taken the turn");
    }
    // deref iterator then deref pointer
    return **(current_start++);
}

void GameState::multiply_point(int multiplier) {
    point *= multiplier;
}

void GameState::reverse_queue() {
    std::reverse(current_start, current_end);
    --current_end;
}

void GameState::end_round() {
    round += 1;
    current_start = queue.begin();
    current_end = queue.end();
}

void GameState::start_game() {
    if (round != 0) {
        throw GameStateException("Game already started");
    }
    point = 64;
    for (auto it = player_list.begin(); it != player_list.end(); ++it) {
        queue.push_back(&(*it));
    }
    current_start = queue.begin();
    current_end = queue.end();
    round = 1;
}

void GameState::restart_game() {
    queue.clear();
    point = 0;
    round = 0;
}

void GameState::print() {
    auto temp = current_start;
    while (temp != current_end) {
        std::cout << (*temp)->num << " ";
        ++temp;
    }
    std::cout << std::endl;

}
