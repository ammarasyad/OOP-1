#ifndef UTIL_H
#define UTIL_H


//class DeckInventory;
//class PlayerCard;
//class Player;

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
//#include "cards.hpp"
//#include "deckCard.hpp"
#include "deckinventory.hpp"
//class PlayerCard;
#include "cards.hpp"
//class PlayerCard;
//class DeckInventory;
//class DeckCard;
#include "generalexceptions.hpp"

class Util{
    public:
        static DeckInventory readDeck(std::string file){
            std::ifstream reader(file.c_str());

            DeckInventory deck(52);

            int num;
            std::string color;

            std::string line;
            while (std::getline(reader, line))
            {
                std::istringstream iss(line);

                
                if (!(iss >> num >> color)) { throw UtilException("input file error."); } // error
                if(color == "Merah") {
                    deck.addToDeck(PlayerCard(num, RED));
                } else if(color == "Kuning") {
                    deck.addToDeck(PlayerCard(num, YELLOW));
                } else if(color == "Hijau") {
                    deck.addToDeck(PlayerCard(num, GREEN));
                } else if(color == "Biru") {
                    deck.addToDeck(PlayerCard(num, BLUE));
                }
                // process pair (a,b)
            }
            return deck;
        }

        template <class T>
        static T max(std::vector<T>& array) {
            T maximum = array.at(0);
            for(int i = 0; i < array.size(); i++){
                maximum = array.at(i) > maximum ? array.at(i) : maximum;
            }

            return maximum;
        }

};

#endif