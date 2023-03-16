#include "tableCards.hpp"

TableCards::TableCards() {}

TableCards::TableCards(LimitedInventory<PlayerCard> inventory) {
    inventory_ = inventory;
}

LimitedInventory<PlayerCard> TableCards::getInventory(){
    return inventory_;
}
void TableCards::setInventory(LimitedInventory<PlayerCard> inventory){
    inventory_ = inventory;
}

void TableCards::addItem(PlayerCard card) {
    inventory_ = inventory_ + card;
}
void TableCards::removeItem(PlayerCard card) {
    inventory_ = inventory_ - card;
}
        
PlayerCard TableCards::getItemAt(int index) {
    return inventory_.at(index);
}

void TableCards::reset(){
    inventory_.clear();
}

