#include "gamestate.hpp"
#include "generalexceptions.hpp"
#include <bits/stdc++.h>

int GameState::creationCount;

GameState::GameState(std::vector<Player>& player_list)
        : playerList(player_list), gamePoint(0), round(0), deck() {
    if (creationCount > 0) {
        std::cout << "WARNING: This is not the first request of GameState creation. Please revisit the code if"
            << " this code is not for testing" << std::endl;
    }
    creationCount += 1;
}

GameState::GameState(std::vector<Player>& player_list, DeckInventory& deck_)
        : playerList(player_list), gamePoint(0), round(0), deck(deck_) {
    if (creationCount > 0) {
        std::cout << "WARNING: This is not the first request of GameState creation. Please revisit the code if"
            << " this code is not for testing" << std::endl;
    }
    creationCount += 1;
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

std::vector<Player*>::iterator &GameState::getStartIterator() {
    return currentStart;
}

void GameState::reverseQueue() {
    auto temp = queue.begin();
    while (temp != queue.end()) {
        std::cout << (**temp).getPlayerId() << " ";
        ++temp;
    }
    std::cout << std::endl;
    std::reverse(currentStart+1, currentEnd);
    std::reverse(queue.begin(), currentStart+1);
    temp = queue.begin();
    while (temp != queue.end()) {
        std::cout << (**temp).getPlayerId() << " ";
        ++temp;
    }
    std::cout << std::endl;
}

Player& GameState::nextTurn() {
    if (currentStart == currentEnd) {
        throw GameStateException((char*)"last player had taken the turn");
    }
    if (round >= 7) {
        throw GameStateException((char*)"Exceeded round limit");
    }

    Player *next_player = *(currentStart + 1);
    ++currentStart;
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
    Player *queue_first = *(queue.begin());
    queue.erase(queue.begin());
    queue.push_back(queue_first);
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

std::vector<Player> &GameState::getPlayerList() {
    return playerList;
}

std::vector<int> GameState::getNextTurnIds() {
    std::vector<int> nextids;
    for (auto it = queue.begin()+1; it != queue.end(); ++it) {
        nextids.push_back((**it).getPlayerId());
    }
    nextids.push_back((**queue.begin()).getPlayerId());
    return nextids;
}

DeckCard& GameState::getDeck() {
    return deck;
}


