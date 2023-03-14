#include "playerinventory.hpp"

void PlayerInventory::setAbilityUsed() {
    abilityAvailable = false;
}

bool PlayerInventory::isAbilityAvailable() const {
    return abilityAvailable;
}

void PlayerInventory::setAbilityCard(AbilityCard &card) {
    *abilityCard = card;
    abilityAvailable = true;
}

PlayerInventory::PlayerInventory(): LimitedInventory(15), abilityAvailable(false) {

}

void PlayerInventory::resetPlayer() {
    deck.clear();
    abilityAvailable = false;
    abilityCard = nullptr;
}
