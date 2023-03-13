#include "player.hpp"

int Player::PLAYER_AMOUNT = 0;

Player::Player() : playerId_(PLAYER_AMOUNT) {
    PLAYER_AMOUNT++;
}

Player::Player(Deck hand) : hand_(hand), playerId_(PLAYER_AMOUNT) {
    PLAYER_AMOUNT++;
}

void Player::showInventory(){
    std::cout << "player number-" << playerId_ << "hand :" << std::endl;
    hand_.show();
}

int Player::getPoint(){
    return point_;
}

void Player::setPoint(int point){
    point_ = point;
}

void Player::addPoint(int amount){
    point_ += amount;
}

Deck Player::getHand(){
    return hand_;
}

void Player::setHand(Deck hand){
    hand_ = hand;
}