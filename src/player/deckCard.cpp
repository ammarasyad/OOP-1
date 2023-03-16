#include "deckCard.hpp"

DeckCard::DeckCard() {}

DeckCard::DeckCard(LimitedInventory<PlayerCard> inventory) {
    inventory_ = inventory;
}

LimitedInventory<PlayerCard> DeckCard::getInventory(){
    return inventory_;
}
void DeckCard::setInventory(LimitedInventory<PlayerCard> inventory){
    inventory_ = inventory;
}

void DeckCard::addItem(PlayerCard card) {
    inventory_ = inventory_ + card;
}
void DeckCard::removeItem(const PlayerCard& card) {
    inventory_ = inventory_ - card;
}
        
PlayerCard DeckCard::getItemAt(const int& index) const{
    return inventory_.at(index);
}

PlayerCard DeckCard::drawACard(){
    PlayerCard temp = getItemAt(0);
    removeItem(temp);

    return temp;
}

void DeckCard::reset(){
    inventory_.clear();
}