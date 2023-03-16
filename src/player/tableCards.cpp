#include "tableCards.hpp"

TableCards::TableCards() {
    inventory_ = new LimitedInventory<PlayerCard>(5);
}

TableCards::TableCards(LimitedInventory<PlayerCard> inventory) {
    inventory_ = &inventory;
}

LimitedInventory<PlayerCard> TableCards::getInventory() const{
    return *inventory_;
}
void TableCards::setInventory(LimitedInventory<PlayerCard> inventory){
    inventory_ = &inventory;
}

void TableCards::addItem(const PlayerCard& card) {
    *inventory_ = *inventory_ + card;
}
void TableCards::removeItem(const PlayerCard& card) {
    *inventory_ = *inventory_ - card;
}
        
PlayerCard TableCards::getItemAt(const int& index) {
    return inventory_->at(index);
}

void TableCards::reset(){
    inventory_->clear();
}

