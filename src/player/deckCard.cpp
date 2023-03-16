#include "deckCard.hpp"

DeckCard::DeckCard() {
    inventory_ = new DeckInventory();
    for(int i = 0; i < 13; i++){
        inventory_->addToDeck(PlayerCard(i+1, RED));
        inventory_->addToDeck(PlayerCard(i+1, YELLOW));
        inventory_->addToDeck(PlayerCard(i+1, BLUE));
        inventory_->addToDeck(PlayerCard(i+1, GREEN));
    }

}

DeckCard::DeckCard(DeckInventory& inventory) {
    inventory_ = &inventory;
}

DeckInventory DeckCard::getInventory() const {
    return *inventory_;
}
void DeckCard::setInventory(DeckInventory inventory){
    inventory_ = &inventory;
}

void DeckCard::addItem(const PlayerCard& card) {
    *inventory_ += card;
}
void DeckCard::removeItem(const PlayerCard& card) {
    *inventory_ -= card;
}
        
PlayerCard DeckCard::getItemAt(const int& index) {
    return inventory_->at(index);
}

PlayerCard DeckCard::drawACard(){
    PlayerCard temp = getItemAt(0);
    removeItem(temp);

    return temp;
}

void DeckCard::shuffle(){
    inventory_->shuffle();
}

void DeckCard::reset(){
    inventory_->clear();
    for(int i = 0; i < 13; i++){
        inventory_->addToDeck(PlayerCard(i+1, RED));
        inventory_->addToDeck(PlayerCard(i+1, YELLOW));
        inventory_->addToDeck(PlayerCard(i+1, BLUE));
        inventory_->addToDeck(PlayerCard(i+1, GREEN));
    }
}