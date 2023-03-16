#include "player.hpp"
#include "generalexceptions.hpp"

int Player::PLAYER_AMOUNT = 0;

Player::Player() : playerId_(PLAYER_AMOUNT), usedCommand_(false), abilityLess_(false), point_(0) {
    PLAYER_AMOUNT++;
}

Player::Player(std::string name) : Player() {
    name_ = name;
}

Player::Player(PlayerInventory inventory) : playerId_(PLAYER_AMOUNT), usedCommand_(false), abilityLess_(false), point_(0) {
    inventory_ = &inventory;
    PLAYER_AMOUNT++;
    //for loop find highest color
}

Player::Player(PlayerInventory inventory, std::string name) : Player(inventory) {
    name_ = name;

}

//virtual func implementation
PlayerInventory Player::getInventory() const{
    return *inventory_;
}

void Player::setInventory(PlayerInventory inventory){
    inventory_ = &inventory;
}

void Player::addItem(const PlayerCard& card){
    *inventory_  += card;
}
void Player::removeItem(const PlayerCard& card) {
    *inventory_ -= card;
}

PlayerCard Player::getItemAt(const int& index){
     return inventory_->at(index);
}

void Player::reset(){
    inventory_->resetPlayer();
    point_ = 0;
    usedCommand_ = false;
    abilityLess_ = false;
}

void Player::resetHand(){
    inventory_->resetPlayer();
    usedCommand_ = false;
    abilityLess_ = false;
}

void Player::setAbilityCard(const AbilityCard& abilityCard) {
    inventory_->setAbilityCard(abilityCard);
}


bool Player::useAbilityCard(const AbilityCard& abilityCard){
    return inventory_->checkAbilityMatchAndUse(abilityCard);
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

void Player::setAbilityLess(){
    abilityLess_ = true;
}
bool Player::isAbilityLess(){
    return abilityLess_;
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

void Player::setName(std::string name){
    name_ = name;
}

std::string Player::getName() const {
    return name_;
}

//operator
Player& Player::operator=(const Player& other){
    name_ = other.name_;
    point_ = other.point_;
    usedCommand_ = other.usedCommand_;
    abilityLess_ = other.abilityLess_;

    return *this;
}

bool Player::operator<(const Player& other) const{
    if(point_ < other.point_){
        return true;
    } else {
        return false;
    }
}
bool Player::operator>(const Player& other) const{
    if(point_ > other.point_){
        return true;
    } else {
        return false;
    }
}

bool Player::operator==(const Player& other) const{
    return point_ == other.point_ && name_ == other.name_ && usedCommand_ == other.usedCommand_ && abilityLess_ == other.abilityLess_;
    // for(int i = 0; i < inventory_)
    //need sort

}