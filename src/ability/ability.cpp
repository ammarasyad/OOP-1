#include "headers/ability.hpp"
#include "gamestate.hpp"
#include "player.hpp"
#include <iostream>
using namespace std;

Ability::Ability(GameState &state) : state(state) {}

int Ability::getId() const {
    return this->abilityCardId;
}

ReRoll::ReRoll(GameState& state) : Ability(state) {
    this->abilityCardId = REROLL;
}

void ReRoll::consume() {
    if (checkAbilityCard()) {
        cout << "Melakukan pembuangan kartu yang sedang dimiliki" << endl;
        Player &temp = getCurrentPlayer();
        temp.removeItem();
        cout << "Kamu mendapatkan 2 kartu baru yaitu:";
        temp.addItem();
        temp.addItem();
    }
    else {
        cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability REROLL.";
    }
}

Double::Double(GameState& state) : Ability(state) {
    this->abilityCardId = DOUBLE;
}

void Double::consume() {
    long long int before = getPoint();
    long long int after = before * 2;
    multiplyPoint(2);

    cout << "melakukan DOUBLE! Poin hadiah naik dari " << before << " menjadi " << after << "!" << endl;
}

Quadruple::Quadruple(GameState& state) : Ability(state) {
    this->abilityCardId = QUADRUPLE;
}

void Quadruple::consume() {
    long long int before = getPoint();
    long long int after = before * 2;
    if (checkAbilityCard()) { //belum ada
        multiplyPoint(4);

        cout << "melakukan QUADRUPLE! Poin hadiah naik dari " << before << " menjadi " << after << "!" << endl;
    }
    else {
        cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability QUADRUPLE." << endl;
    } 
}

Half::Half(GameState& state) : Ability(state) {
    this->abilityCardId = HALF;
}

void Half::consume() {
    long long int before = getPoint();

    if (before > 1) {
        long long int after = before / 2;
        dividePoint(2);

        cout << "melakukan HALF! Poin hadiah turun dari " << before << " menjadi " << after << "!" << endl;
    }
    else {
        cout << "melakukan HALF! Sayangnya poin hadiah sudah bernilai 1. Poin hadiah tidak berubah.. Giliran dilanjut!" << endl;
    }
}

Quarter::Quarter(GameState& state) : Ability(state) {
    this->abilityCardId = QUARTER;
}

void Quarter::consume() {
    long long int before = getPoint();

    if (before > 2 && checkAbilityCard()) { //belum ada
        long long int after = before / 4;
        dividePoint(4);

        cout << "melakukan QUARTER! Poin hadiah turun dari " << before << " menjadi " << after << "!" << endl;
    }
    else {
        cout << "melakukan QUARTER! Sayangnya poin hadiah sudah bernilai 1. Poin hadiah tidak berubah.. Giliran dilanjut!" << endl;
    }
}

Reverse::Reverse(GameState& state) : Ability(state) {
    this->abilityCardId = REVERSE;
}

void Reverse::consume() {
    if (CantUseAbility) {
        cout << "Oops, kartu ability reversemu telah dimatikan sebelumnya:(. Silahkan lakukan perintah lain." << endl;
    }
    else {
        if (checkAbilityCard()) {
            cout << " melakukan REVERSE!" << endl;
        }
        else {
            cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability REVERSE." << endl;
        } 
    }
}

SwapCard::SwapCard(GameState& state) : Ability(state) {
    this->abilityCardId = SWAPCARD;
}

void SwapCard::consume() {
    if (CantUseAbility) {
        cout << "Oops, kartu ability swapmu telah dimatikan sebelumnya:(. Silahkan lakukan perintah lain." << endl;
    }
    else {
        if (checkAbilityCard()) {
            cout << " melakukan SWAPCARD!" << endl;
            cout << "Silahkan pilih pemain yang kartunya ingin anda tukar :" << endl;
        }
        else {
            cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability SWAPCARD." << endl;
        } 
    }
}

Switch::Switch(GameState& state) : Ability(state) {
    this->abilityCardId = SWITCH;
}

void Switch::consume() {
    if (CantUseAbility) {
        cout << "Oops, kartu ability switchmu telah dimatikan sebelumnya:(. Silahkan lakukan perintah lain." << endl;
    }
    else {
        if (checkAbilityCard()) {
            cout << " melakukan SWITCH!" << endl;
            cout << "Silahkan pilih pemain yang kartunya ingin anda tukar :" << endl;
        }
        else {
            cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability SWITCH." << endl;
        } 
    }
}

Abilityless::Abilityless(GameState& state) : Ability(state) {
    this->abilityCardId = ABILITYLESS;
}

void Abilityless::consume() {}
