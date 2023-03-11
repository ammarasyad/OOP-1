#ifndef TUBESOOP_COMBO_HPP
#define TUBESOOP_COMBO_HPP
#include <iostream>
#include <vector>
#include "hand.hpp"
#include "cards.hpp"


class Combination : public virtual Hand {
public:
    template <typename... Cards>
    explicit Combination(Cards...);
    explicit Combination(vector<Card>);
    float value() const override;
    vector<Card> getCards() const;
    Card& operator[](int);
//    bool operator>(Combination&);
//    bool operator<(Combination&);
//    bool operator==(Combination&);
//    bool operator!=(Combination&);
//    bool operator>=(Combination&);
//    bool operator<=(Combination&);
private:
    vector<Card> cards;
};

#endif
