#include "playerinventory.hpp"

void PlayerInventory::setAbilityUsed() {
    delete abilityCard;
    abilityAvailable = false;
}

bool PlayerInventory::isAbilityAvailable() const {
    return abilityAvailable;
}

void PlayerInventory::setAbilityCard(AbilityCard &card) {
    abilityCard = new AbilityCard(card);
    abilityAvailable = true;
}

PlayerInventory::PlayerInventory(): LimitedInventory(15), abilityAvailable(false) {

}

PlayerInventory::PlayerInventory(const PlayerInventory& other) : PlayerInventory() {
    abilityAvailable = other.abilityAvailable;
    deck = other.deck;
    deckSize = other.deckSize;
    if(abilityAvailable){
        abilityCard = new AbilityCard(*(other.abilityCard));
    } else {
        abilityCard = nullptr;
    }
}

PlayerInventory::~PlayerInventory(){
    delete abilityCard;
}

void PlayerInventory::resetPlayer() {
    clear();
    abilityAvailable = false;
    delete abilityCard;
    abilityCard = nullptr;
}

bool PlayerInventory::isAbilityMatch(AbilityCard &card) {
    if (abilityAvailable && card.getId()==this->abilityCard->getId()) {
        return true;
    }
    return false;
}

bool PlayerInventory::checkAbilityMatchAndUse(AbilityCard &card) {
    if (this->isAbilityMatch(card)) {
        abilityAvailable = false;
        return true;
    }
    return false;
}

PlayerInventory &PlayerInventory::operator+=(PlayerCard &card) {
    LimitedInventory::operator+=(card);
    return *this;
}

PlayerInventory PlayerInventory::operator+(PlayerCard &card) const {
    PlayerInventory temp(*this);
    return temp += card;
}

PlayerInventory &PlayerInventory::operator-=(PlayerCard &card) {
    LimitedInventory::operator-=(card);
    return *this;
}

PlayerInventory PlayerInventory::operator-(PlayerCard &card) const {
    PlayerInventory temp(*this);
    return temp -= card;
}

PlayerInventory operator+(PlayerCard &card, PlayerInventory &inventory) {
    return inventory + card;
}

PlayerInventory operator-(PlayerCard &card, PlayerInventory &inventory) {
    return inventory - card;
}

PlayerInventory& PlayerInventory::operator=(PlayerInventory& other){
    deck = other.deck;
    deckSize = other.deckSize;
    delete abilityCard;
    abilityAvailable = other.abilityAvailable;
    if(abilityAvailable){
        abilityCard = new AbilityCard(*(other.abilityCard));
    } else {
        abilityCard = nullptr;
    }


}