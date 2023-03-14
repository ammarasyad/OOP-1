#include "gamestate.hpp"
#include "generalexceptions.hpp"
#include <bits/stdc++.h>

GameState::GameState(std::vector<Player>& player_list)
        : playerList(player_list), gamePoint(0), round(0) {
}

long long int GameState::getPoint() const {
    return gamePoint;
}

int GameState::getRound() const {
    return round;
}

Player& GameState::getPlayerById(int player_id) {
    if (player_id > 7 || player_id <= 0) {
        throw GameStateException((char*)"player id does not exist");
    }
    return playerList.at(player_id);
}

Player &GameState::getCurrentPlayer() {
    return **currentStart;
}

std::vector<Player*>& GameState::getQueue() {
    if (round == 0) {
        throw GameStateException((char*)"invalid operation on round-0");
    }
    return queue;
}

void GameState::reverseQueue() {
    std::reverse(currentStart, currentEnd);
    --currentEnd;
}

Player& GameState::nextTurn(char reverse) {
    if (currentStart == currentEnd) {
        throw GameStateException((char*)"last player had taken the turn");
    }
    if (round >= 7) {
        throw GameStateException((char*)"Exceeded round limit");
    }

    if (reverse == 'y' || reverse == 'Y') {
        reverseQueue();
        return **(currentStart);
    }
    Player *next_player = *(currentStart + 1);
    if ((**currentStart).getPlayerId() == firstTurnId) {
        Player *temp = *currentStart;
        queue.erase(currentStart);
        queue.push_back(temp);
        next_player = *currentStart;

    }
    // round ended
    if (currentStart == currentEnd) {
        endRound();
    }

    return *next_player;
}

void GameState::multiplyPoint(int multiplier) {
    if (gamePoint == 1)
        return;
    gamePoint *= multiplier;
}

void GameState::dividePoint(int divider) {
    if (gamePoint == 1)
        return;
    gamePoint /= divider;
}

void GameState::endRound() {
    round += 1;
    currentStart = queue.begin();
    currentEnd = queue.end();
    firstTurnId = (**currentStart).getPlayerId();
}

void GameState::startGame() {
    if (round != 0) {
        throw GameStateException((char*)"Game already started");
    }
    gamePoint = 64;
    if (queue.empty()) {
        for (auto & it : playerList) {
            queue.push_back(&it);
        }
    }
    firstTurnId = (*queue.front()).getPlayerId();
    currentStart = queue.begin();
    currentEnd = queue.end();
    round = 1;
}

void GameState::restartGame() {
    gamePoint = 0;
    round = 1;
    for (auto &it: playerList) {
        // reset all players' inventory
    }
}

void GameState::print() {
    auto temp = currentStart;
    std::cout << "round " << round << ": ";
    while (temp != currentEnd) {
        std::cout << (*temp)->getPlayerId() << " ";
        ++temp;
    }
    std::cout << std::endl;

}


