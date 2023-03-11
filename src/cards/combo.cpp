#include "combo.hpp"

#include <utility>

template <typename... Cards>
Combination::Combination(Cards... cards) {
    for (auto card : {cards...}) {
        this->cards.push_back(card);
    }
}

Combination::Combination(vector<Card> cards) {
    copy(cards.begin(), cards.end(), back_inserter(this->cards));
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
