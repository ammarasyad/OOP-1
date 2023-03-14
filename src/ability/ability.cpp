#include "ability.hpp"
#include <iostream>
using namespace std;

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

void Double::consume() {
    long long int before = getPoint();
    long long int after = before * 2;
    multiplyPoint(2);

    cout << "melakukan DOUBLE! Poin hadiah naik dari " << before << " menjadi " << after << "!" << endl;
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

void Abilityless::consume() {}
