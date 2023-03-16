#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "deckinventory.hpp"
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

                
                if (!(iss >> num >> color)) { throw UtilException((char*)"input file error."); } // error
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
};