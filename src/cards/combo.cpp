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

float Combination::getValue() {

}

vector<PlayerCard> Combination::getCards() const {
    return this->cards;
}

CombinationType Combination::getType() const {
    return this->type;
}

PlayerCard &Combination::operator[](int index) {
    return this->cards[index];
}

CombinationType Combination::calculateType() {
    CombinationType result = HIGH_PAIR;
    // Look at this mess
    for (int i = 0; i < this->cards.size() - 1; i++) {
        if (this->cards[i] == this->cards[i + 1]) {
            result = PAIR;
        } else if (i < this->cards.size() - 3 && this->cards[i] == this->cards[i + 1] &&
                   this->cards[i + 2] == this->cards[i + 3]) {
            result = TWO_PAIR;
        } else if (i < this->cards.size() - 4 && this->cards[i] == this->cards[i + 1] &&
                   this->cards[i + 2] == this->cards[i + 3]) {
            result = THREE_OF_A_KIND;
        } else if (i < this->cards.size() - 4 && this->cards[i].getNumber() == this->cards[i + 1].getNumber() + 1 &&
                   this->cards[i + 2].getNumber() == this->cards[i + 3].getNumber() + 1) {
            result = STRAIGHT;
        } else if (i < this->cards.size() - 4 && this->cards[i].getColor() == this->cards[i + 1].getColor() &&
                   this->cards[i + 2].getColor() == this->cards[i + 3].getColor() &&
                   this->cards[i + 4].getColor() == this->cards[i + 5].getColor()) {
            result = FLUSH;
        } else if (i < this->cards.size() - 4 && this->cards[i] == this->cards[i + 1] &&
                   this->cards[i + 2] == this->cards[i + 3] && this->cards[i + 4] == this->cards[i + 5]) {
            result = FULL_HOUSE;
        } else if (i < this->cards.size() - 4 && this->cards[i] == this->cards[i + 1] &&
                   this->cards[i + 2] == this->cards[i + 3] && this->cards[i + 4] == this->cards[i + 5]) {
            result = FOUR_OF_A_KIND;
        } else if (i < this->cards.size() - 4 && this->cards[i].getNumber() == this->cards[i + 1].getNumber() + 1 &&
                   this->cards[i + 2].getNumber() == this->cards[i + 3].getNumber() + 1 &&
                   this->cards[i].getColor() == this->cards[i + 1].getColor() &&
                   this->cards[i + 2].getColor() == this->cards[i + 3].getColor()) {
            result = STRAIGHT_FLUSH;
        }
    }
    return result;
}

PlayerCard Combination::getHighestCard() {
    PlayerCard highestValue = this->cards[0];
    for (const auto &card: this->cards) {
        if (card > highestValue) {
            highestValue = card;
        }
    }
    return highestValue;
}

// I think this is still unfinished
float Combination::getComboTypeValue() {
    switch (this->type) {
        case HIGH_PAIR:
            return getHighestCard().getValue();
        case PAIR: {
            this->type = PAIR;
            float pairValue = 0;
            for (int i = 0; i < this->cards.size() - 1; i++) {
                if (this->cards[i].getValue() == this->cards[i + 1].getValue()) {
                    pairValue = this->cards[i].getValue();
                    break;
                }
            }
            return pairValue + 13.9f +
                   ((float) this->cards[0].getColor() * 0.3f); // 13.9f is the highest value of a high card
        }
        case TWO_PAIR: {
            this->type = TWO_PAIR;
            float twoPairValue = 0;
            for (int i = 0; i < this->cards.size() - 3; i++) {
                if (this->cards[i].getValue() == this->cards[i + 1].getValue() &&
                    this->cards[i + 2].getValue() == this->cards[i + 3].getValue()) {
                    twoPairValue = this->cards[i].getValue();
                    break;
                }
            }
            return twoPairValue + (2 * 13.9f) +
                   ((float) this->cards[0].getColor() * 0.3f); // 2 * 13.9f is the highest value of a one pair
        }
        case THREE_OF_A_KIND: {
            this->type = THREE_OF_A_KIND;
            float threeOfAKindValue = 0;
            for (int i = 0; i < this->cards.size() - 2; i++) {
                if (this->cards[i].getValue() == this->cards[i + 1].getValue() &&
                    this->cards[i + 1].getValue() == this->cards[i + 2].getValue()) {
                    threeOfAKindValue = 3 * this->cards[i].getValue();
                    break;
                }
            }
            return threeOfAKindValue + (3 * 13.9f) + ((float) this->cards[0].getColor() * 0.3f);
        }
        case STRAIGHT: {
            this->type = STRAIGHT;
            float straightValue = this->cards[0].getValue();
            for (int i = 0; i < this->cards.size() - 1; i++) {
                if (this->cards[i].getValue() - this->cards[i + 1].getValue() != 1) {
                    straightValue = 0;
                    break;
                }
            }
            return straightValue + (4 * 13.9f) + ((float) this->cards[0].getColor() * 0.3f);
        }
        case FLUSH: {
            this->type = FLUSH;
            float flushValue = this->cards[0].getValue();
            for (int i = 0; i < this->cards.size() - 1; i++) {
                if (this->cards[i].getColor() != this->cards[i + 1].getColor()) {
                    flushValue = 0;
                    break;
                }
            }
            return flushValue + (5 * 13.9f) + ((float) this->cards[0].getColor() * 0.3f);
        }
        case FULL_HOUSE: {
            this->type = FULL_HOUSE;
            float fullHouseValue = 0;
            for (int i = 0; i < this->cards.size() - 4; i++) {
                if (this->cards[i].getValue() == this->cards[i + 1].getValue() &&
                    this->cards[i + 1].getValue() == this->cards[i + 2].getValue() &&
                    this->cards[i + 3].getValue() == this->cards[i + 4].getValue()) {
                    fullHouseValue = this->cards[i].getValue();
                    break;
                }
            }
            return fullHouseValue + (6 * 13.9f) + ((float) this->cards[0].getColor() * 0.3f);
        }
        case FOUR_OF_A_KIND: {
            this->type = FOUR_OF_A_KIND;
            float fourOfAKindValue = 0;
            for (int i = 0; i < this->cards.size() - 3; i++) {
                if (this->cards[i].getValue() == this->cards[i + 1].getValue() &&
                    this->cards[i + 1].getValue() == this->cards[i + 2].getValue() &&
                    this->cards[i + 2].getValue() == this->cards[i + 3].getValue()) {
                    fourOfAKindValue = this->cards[i].getValue();
                    break;
                }
            }
            return fourOfAKindValue + (7 * 13.9f);
        }
        case STRAIGHT_FLUSH: {
            this->type = STRAIGHT_FLUSH;
            float straightFlushValue = this->cards[0].getValue();
            for (int i = 0; i < this->cards.size() - 1; i++) {
                if (this->cards[i].getValue() - this->cards[i + 1].getValue() != 1 ||
                    this->cards[i].getColor() != this->cards[i + 1].getColor()) {
                    straightFlushValue = 0;
                    break;
                }
            }
            return straightFlushValue + (8 * 13.9f) + ((float) this->cards[0].getColor() * 0.3f);
        }
        default: {
            this->type = calculateType();
            return getComboTypeValue();
        }
    }
}
