#include <algorithm>
#include "headers/combo.hpp"

template<typename... PlayerCards>
Combination::Combination(PlayerCards... cards) : Combination(vector<PlayerCard>{cards...}) {

}

Combination::Combination(vector<PlayerCard> &cards) {
    sort(cards.begin(), cards.end(), [](const PlayerCard &card1, const PlayerCard &card2) {
        return card1 > card2;
    });
    this->cards = cards;
    this->type = calculateType();
}

// TODO : Implement combo value
float Combination::getValue() {
    switch (this->type) {
        case HIGH_PAIR:
            break;
        case PAIR:
            break;
        case TWO_PAIR:
            break;
        case THREE_OF_A_KIND:
            break;
        case STRAIGHT:
            break;
        case FLUSH:
            break;
        case FULL_HOUSE:
            break;
        case FOUR_OF_A_KIND:
            break;
        case STRAIGHT_FLUSH:
            break;
    }
}

vector<PlayerCard> Combination::getCards() const {
    return this->cards;
}

CombinationType Combination::getType() const {
    return this->type;
}

string Combination::getTypeString() {
    return this->comboString[this->type];
}

PlayerCard& Combination::operator[](int index) {
    return this->cards[index];
}

// Comparisons haven't been tested yet
bool Combination::operator>(Combination& combo) {
    if (this->type > combo.getType()) {
        return true;
    } else if (this->type == combo.getType()) {
        for (int i = 0; i < this->cards.size(); i++) {
            if (this->cards[i] > combo[i]) {
                return true;
            } else if (this->cards[i] < combo[i]) {
                return false;
            }
        }
    }
    return false;
}

bool Combination::operator<(Combination& combo) {
    if (this->type < combo.getType()) {
        return true;
    } else if (this->type == combo.getType()) {
        for (int i = 0; i < this->cards.size(); i++) {
            if (this->cards[i] < combo[i]) {
                return true;
            } else if (this->cards[i] > combo[i]) {
                return false;
            }
        }
    }
    return false;
}

bool Combination::operator==(Combination& combo) {
    if (this->type == combo.getType()) {
        for (int i = 0; i < this->cards.size(); i++) {
            if (this->cards[i] != combo[i]) {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool Combination::operator!=(Combination& combo) {
    return !(*this == combo);
}

bool Combination::operator>=(Combination& combo) {
    return *this > combo || *this == combo;
}

bool Combination::operator<=(Combination& combo) {
    return *this < combo || *this == combo;
}

CombinationType Combination::calculateType() {
    if (this->isStraightFlush()) {
        return STRAIGHT_FLUSH;
    } else if (this->isFourOfAKind()) {
        return FOUR_OF_A_KIND;
    } else if (this->isFullHouse()) {
        return FULL_HOUSE;
    } else if (this->isFlush()) {
        return FLUSH;
    } else if (this->isStraight()) {
        return STRAIGHT;
    } else if (this->isThreeOfAKind()) {
        return THREE_OF_A_KIND;
    } else if (this->isTwoPair()) {
        return TWO_PAIR;
    } else if (this->isPair()) {
        return PAIR;
    }
    return HIGH_PAIR;
}

//PlayerCard Combination::getHighestCard() {
//    PlayerCard highestValue = this->cards[0];
//    for (const auto& card: this->cards) {
//        if (card > highestValue) {
//            highestValue = card;
//        }
//    }
//    return highestValue;
//}

bool Combination::isStraightFlush() {
    return this->isFlush() && this->isStraight();
}

bool Combination::isFourOfAKind() {
    for (int i = 0; i < this->cards.size() - 3; i++) {
        if (this->cards[i].getNumber() == this->cards[i + 1].getNumber() &&
            this->cards[i + 1].getNumber() == this->cards[i + 2].getNumber() &&
            this->cards[i + 2].getNumber() == this->cards[i + 3].getNumber()) {
            return true;
        }
    }
    return false;
}

bool Combination::isFullHouse() {
    for (int i = 0; i < this->cards.size() - 4; i++) {
        if ((this->cards[i].getNumber() == this->cards[i + 1].getNumber() &&
            this->cards[i + 1].getNumber() == this->cards[i + 2].getNumber() &&
            this->cards[i + 3].getNumber() == this->cards[i + 4].getNumber()) ||
            (this->cards[i].getNumber() == this->cards[i + 1].getNumber() &&
            this->cards[i + 2].getNumber() == this->cards[i + 3].getNumber() &&
            this->cards[i + 3].getNumber() == this->cards[i + 4].getNumber())) {
            return true;
        }
    }
    return false;
}

bool Combination::isFlush() {
    for (int i = 0; i < this->cards.size() - 1; i++) {
        if (this->cards[i].getColor() != this->cards[i + 1].getColor()) {
            return false;
        }
    }
    return true;
}

bool Combination::isStraight() {
    for (int i = 0; i < this->cards.size() - 1; i++) {
        if (this->cards[i].getNumber() - this->cards[i + 1].getNumber() != 1) {
            return false;
        }
    }
    return true;
}

bool Combination::isThreeOfAKind() {
    for (int i = 0; i < this->cards.size() - 2; i++) {
        if (this->cards[i].getNumber() == this->cards[i + 1].getNumber() &&
            this->cards[i + 1].getNumber() == this->cards[i + 2].getNumber()) {
            return true;
        }
    }
    return false;
}

bool Combination::isTwoPair() {
    int pairs = 0;
    for (int i = 0; i < this->cards.size() - 1; i++) {
        if (this->cards[i].getNumber() == this->cards[i + 1].getNumber()) {
            pairs++;
            i++;
        }
    }
    return pairs == 2;
}

bool Combination::isPair() {
    for (int i = 0; i < this->cards.size() - 1; i++) {
        if (this->cards[i].getNumber() == this->cards[i + 1].getNumber()) {
            return true;
        }
    }
    return false;
}
