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

void PlayerInventory::resetPlayer() {
    deck.clear();
    abilityAvailable = false;
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
