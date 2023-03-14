#include "player.hpp"
#include "generalexceptions.hpp"

int Player::PLAYER_AMOUNT = 0;

Player::Player() : playerId_(PLAYER_AMOUNT), usedCommand_(false), handScore_(-1) {
    PLAYER_AMOUNT++;
}

Player::Player(PlayerInventory inventory) : playerId_(PLAYER_AMOUNT), usedCommand_(false), handScore_(-1) {
    inventory_ = inventory;
    PLAYER_AMOUNT++;
    //for loop find highest color
}

//virtual func implementation
PlayerInventory Player::getInventory(){
    return inventory_;
}

void Player::setInventory(PlayerInventory inventory){
    inventory_ = inventory;
}

void Player::addItem(PlayerCard card){
    // inventory_ = inventory_ + card;
}
void Player::removeItem(PlayerCard card) {
    // inventory_ = inventory_ - card;
}

PlayerCard Player::getItemAt(int index){
    // return inventory_.at(index)
}

float Player::getHandScore(){
    return handScore_;
}
void Player::setHandScore(float handScore){
    handScore_ = handScore;
}

bool Player::haveUsedCommand(){
    return usedCommand_;
}
void Player::canUseCommand(){
    usedCommand_ = false;
}
void Player::cantUseCommand(){
    usedCommand_ = true;
}


int Player::getPlayerId(){
    return playerId_;
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

//operator
bool Player::operator<(Player other){
    if(handScore_ < 0) {
        throw PlayerException("Player hand combination score unknown.");
    }

    if(handScore_ == other.handScore_){
        Color thisColorPriority = GREEN;
        Color otherColorPriority = GREEN;

        for(int i = 0; i < inventory_.getLength(); i++){
            Color tempColor = inventory_.at(i).getColor();
            thisColorPriority = tempColor > thisColorPriority ? tempColor : thisColorPriority;
        }

        for(int i = 0; i < other.inventory_.getLength(); i++){
            Color tempColor = other.inventory_.at(i).getColor();
            otherColorPriority = tempColor > otherColorPriority ? tempColor : otherColorPriority;
        }

        if(thisColorPriority < otherColorPriority){
            return true;
        }
    } else {
        if(handScore_ < other.handScore_){
            return true;
        } else {
            return false;
        }
    }
}
bool operator>(Player);
bool operator==(Player);