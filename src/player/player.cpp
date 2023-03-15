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
PlayerInventory Player::getInventory() const{
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

PlayerCard Player::getItemAt(int index) const{
    // return inventory_.at(index)
}

void Player::setAbilityCard(AbilityCard& abilityCard) {
    inventory_.setAbilityCard(abilityCard);
}


bool Player::useAbilityCard(AbilityCard& abilityCard){
    return inventory_.checkAbilityMatchAndUse(abilityCard);
}

float Player::getHandScore() const{
    return handScore_;
}
void Player::setHandScore(float handScore){
    handScore_ = handScore;
}

bool Player::haveUsedCommand() const{
    return usedCommand_;
}
void Player::canUseCommand(){
    usedCommand_ = false;
}
void Player::cantUseCommand(){
    usedCommand_ = true;
}


int Player::getPlayerId() const{
    return playerId_;
}

int Player::getPoint() const{
    return point_;
}

void Player::setPoint(int point){
    point_ = point;
}

void Player::addPoint(int amount){
    point_ += amount;
}

//operator
bool Player::operator<(const Player& other) const{
    if(handScore_ < 0) {
        throw PlayerException("Player hand combination score unknown.");
    } else {

    }

    if(handScore_ == other.handScore_){
        int thisColorPriority = 1 * GREEN;
        int otherColorPriority = 1 * GREEN;

        for(int i = 0; i < inventory_.getDeckSize(); i++){
            int tempColor = inventory_.at(i).getColor() * inventory_.at(i).getNumber();
            thisColorPriority = tempColor > thisColorPriority ? tempColor : thisColorPriority;
        }

        for(int i = 0; i < other.inventory_.getDeckSize(); i++){
            int tempColor = other.inventory_.at(i).getColor() * other.inventory_.at(i).getNumber();
            otherColorPriority = tempColor > otherColorPriority ? tempColor : otherColorPriority;
        }

        if(thisColorPriority < otherColorPriority){
            return true;
        } else {
            return false;
        }
    } else {
        if(handScore_ < other.handScore_){
            return true;
        } else {
            return false;
        }
    }
}
bool Player::operator>(const Player& other) const{
    if(handScore_ < 0) {
        throw PlayerException("Player hand combination score unknown.");
    }

    if(handScore_ == other.handScore_){
        int thisColorPriority = 1 * GREEN;
        int otherColorPriority = 1 * GREEN;

        for(int i = 0; i < inventory_.getDeckSize(); i++){
            int tempColor = inventory_.at(i).getColor() * inventory_.at(i).getNumber();
            thisColorPriority = tempColor > thisColorPriority ? tempColor : thisColorPriority;
        }

        for(int i = 0; i < other.inventory_.getDeckSize(); i++){
            int tempColor = other.inventory_.at(i).getColor() * other.inventory_.at(i).getNumber();
            otherColorPriority = tempColor > otherColorPriority ? tempColor : otherColorPriority;
        }

        if(thisColorPriority > otherColorPriority){
            return true;
        } else {
            return false;
        }
    } else {
        if(handScore_ > other.handScore_){
            return true;
        } else {
            return false;
        }
    }
}

bool Player::operator==(const Player& other) const{
    bool alike = handScore_ == other.handScore_;
    // for(int i = 0; i < inventory_)
    //need sort

}