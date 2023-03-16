#include "tableCards.hpp"

TableCards::TableCards() {

}

TableCards::TableCards(LimitedInventory<PlayerCard> inventory) {
    inventory_ = inventory;
}

LimitedInventory<PlayerCard> TableCards::getInventory() const{
    return inventory_;
}
void TableCards::setInventory(LimitedInventory<PlayerCard> inventory){
    inventory_ = inventory;
}

void TableCards::addItem(const PlayerCard& card) {
    inventory_ = inventory_ + card;
}
void TableCards::removeItem(const PlayerCard& card) {
    inventory_ = inventory_ - card;
}
        
PlayerCard TableCards::getItemAt(const int& index) const {
    return inventory_.at(index);
}

void TableCards::reset(){
    inventory_.clear();
}

