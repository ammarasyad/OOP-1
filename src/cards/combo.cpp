#include "combo.hpp"

template <typename... Cards>
Combination::Combination(Cards... cards) : Combination(vector<Card>{cards...}) {

}

Combination::Combination(const vector<Card>& cards) : cards(cards) {

}

float Combination::value() const {
    // TODO: Implementasi value untuk combination
//    float sum = 0;
//    for (const auto& card : this->cards) {
//        sum += card.value();
//    }
//    return sum;
}

vector<Card> Combination::getCards() const {
    return this->cards;
}

Card& Combination::operator[](int index) {
    return this->cards[index];
}
