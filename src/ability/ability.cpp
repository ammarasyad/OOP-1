#include "headers/ability.hpp"
#include "gamestate.hpp"
#include "player.hpp"
#include <iostream>
using namespace std;

Ability::Ability(GameState &state) : state(state) {}

int Ability::getId() const {
    return this->abilityCardId;
}

ReRoll::ReRoll(GameState& state) : Ability(state) {
    this->abilityCardId = REROLL;
}

void ReRoll::consume() {
    Player& current = state.getCurrentPlayer();

    PlayerCard firstCard = current.getItemAt(0);
    PlayerCard secondCard = current.getItemAt(1);

    current.removeItem(firstCard);
    current.removeItem(secondCard);

    PlayerCard newFirstCard = state.getDeck().drawACard();
    PlayerCard newSecondCard = state.getDeck().drawACard();

    current.addItem(newFirstCard);
    current.addItem(newSecondCard);    
}

Double::Double(GameState& state) : Ability(state) {
    this->abilityCardId = DOUBLE;
}

void Double::consume() {
    state.multiplyPoint(2);
}

Quadruple::Quadruple(GameState& state) : Ability(state) {
    this->abilityCardId = QUADRUPLE;
}

void Quadruple::consume() {
    state.multiplyPoint(4);
}

Half::Half(GameState& state) : Ability(state) {
    this->abilityCardId = HALF;
}

void Half::consume() {
    state.dividePoint(2);
}

Quarter::Quarter(GameState& state) : Ability(state) {
    this->abilityCardId = QUARTER;
}

void Quarter::consume() {
    state.dividePoint(4);
}

Reverse::Reverse(GameState& state) : Ability(state) {
    this->abilityCardId = REVERSE;
}

void Reverse::consume() {
    state.reverseQueue();
}

SwapCard::SwapCard(GameState& state) : Ability(state) {
    this->abilityCardId = SWAPCARD;
}

void SwapCard::setTarget(int firstTargetId, int secondTargetId, int firstCard, int secondCard) {
    this-> firstTargetId = firstTargetId;
    this-> secondTargetId = secondTargetId;
    this-> firstCard = firstCard;
    this-> secondCard = secondCard;
}

void SwapCard::consume() {
    Player& firstPlayer = state.getPlayerById(firstTargetId);
    Player& secondPlayer = state.getPlayerById(secondTargetId);

    PlayerCard temp1 = firstPlayer.getItemAt(firstCard);
    PlayerCard temp2 = secondPlayer.getItemAt(secondCard);

    firstPlayer.removeItem(temp1);
    firstPlayer.addItem(temp2);

    secondPlayer.removeItem(temp2);
    secondPlayer.addItem(temp1);
}

Switch::Switch(GameState& state) : Ability(state) {
    this->abilityCardId = SWITCH;
}

void Switch::setTarget(int targetId) {
    this-> targetId = targetId;
}

void Switch::consume() {
    Player& selfPlayer = state.getCurrentPlayer();
    Player& targetPlayer = state.getPlayerById(targetId);

    PlayerCard selfCard1 = selfPlayer.getItemAt(1);
    PlayerCard selfCard2 = selfPlayer.getItemAt(2);

    PlayerCard targetCard1 = targetPlayer.getItemAt(1);
    PlayerCard targetCard2 = targetPlayer.getItemAt(2);

    selfPlayer.removeItem(selfCard1);
    selfPlayer.removeItem(selfCard2);
    selfPlayer.addItem(targetCard1);
    selfPlayer.addItem(targetCard2);

    targetPlayer.removeItem(targetCard1);
    targetPlayer.removeItem(targetCard2);
    targetPlayer.addItem(selfCard1);
    targetPlayer.addItem(selfCard2);
}

Abilityless::Abilityless(GameState& state) : Ability(state) {
    this->abilityCardId = ABILITYLESS;
}

void Abilityless::setTarget(int targetId) {
    this-> targetId = targetId;
}

void Abilityless::consume() {
    state.getPlayerById(targetId).setAbilityLess();
}
