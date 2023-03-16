#include "gameio.hpp"
#include <utility>
#include <iostream>

void GameIO::getCommand(GameState& game_state) {
    std::cout << "Masukkan command anda: ";
    std::string command;
    std::cin >> command;

}

void GameIO::nextIO(GameState& game_state) {
    std::cout << "Giliran dilanjut ke pemain selanjutnya" << std::endl;
    game_state.nextTurn();
}

void GameIO::cantUseAbility() {
    std::cout << "Oops, kartu abilitymu telah dimatikan sebelumnya:(. Silahkan lakukan perintah lain." << std::endl;
}

void GameIO::reRollIO(GameState& game_state) {
    ReRoll reroll(game_state);
    if (game_state.getCurrentPlayer().useAbilityCard(AbilityCard(reroll))) {
        std::cout << "Melakukan pembuangan kartu yang sedang dimiliki" << std::endl;
        std::cout << "Kamu mendapatkan 2 kartu baru yaitu:" << std::endl;
        reroll.consume();

        Player& current = game_state.getCurrentPlayer();
        PlayerCard firstCard = current.getItemAt(0);
        PlayerCard secondCard = current.getItemAt(1);
        std::cout << "1. " << firstCard.getNumber() << " " << firstCard.getColor() << std::endl;
        std::cout << "2. " << secondCard.getNumber() << " " << secondCard.getColor() << std::endl;
    }
    else {
        std::cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability REROLL." << std::endl;
    }
}

void GameIO::doubleIO(GameState& game_state) {
    Double doublE(game_state);
    long long int before = game_state.getPoint();
    doublE.consume();
    long long int after = game_state.getPoint();

    std::cout << game_state.getCurrentPlayer().getName() << "melakukan DOUBLE! Poin hadiah naik dari " << before << " menjadi " << after << "!" << std::endl;
}

void GameIO::quadrupleIO(GameState& game_state) {
    Quadruple quadruple(game_state);
    if (game_state.getCurrentPlayer().useAbilityCard(AbilityCard(quadruple))) {
        long long int before = game_state.getPoint();
        quadruple.consume();
        long long int after = game_state.getPoint();

        std::cout << game_state.getCurrentPlayer().getName() << "melakukan QUADRUPLE! Poin hadiah naik dari " << before << " menjadi " << after << "!" << std::endl;
    }
    else {
        std::cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability QUADRUPLE." << std::endl;
    }
}

void GameIO::halfIO(GameState& game_state) {
    Half half(game_state);
    if (game_state.getPoint() > 1) {
        long long int before = game_state.getPoint();
        half.consume();
        long long int after = game_state.getPoint();

        std::cout << game_state.getCurrentPlayer().getName() << "melakukan HALF! Poin hadiah turun dari " << before << " menjadi " << after << "!" << std::endl;
    }
    else {
        std::cout << game_state.getCurrentPlayer().getName() << "melakukan HALF! Sayangnya poin hadiah sudah bernilai 1. Poin hadiah tidak berubah.. Giliran dilanjut!" << std::endl;
    }
}

void GameIO::quarterIO(GameState& game_state) {
    Quarter quarter(game_state);
    if (game_state.getCurrentPlayer().useAbilityCard(AbilityCard(quarter))) {
        if (game_state.getPoint() > 2) {
            long long int before = game_state.getPoint();
            quarter.consume();
            long long int after = game_state.getPoint();

            std::cout << game_state.getCurrentPlayer().getName() << "melakukan QUARTER! Poin hadiah turun dari " << before << " menjadi " << after << "!" << std::endl;
        }
        else {
            std::cout << game_state.getCurrentPlayer().getName() << "melakukan QUARTER! Sayangnya poin hadiah sudah tidak bisa berubah. Poin hadiah tidak berubah.. Giliran dilanjut!" << std::endl;
        }
    }
    else {
        std::cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability QUARTER." << std::endl;
    }
}

void GameIO::reverseIO(GameState& game_state) {
    Reverse reversE(game_state);
    if (game_state.getCurrentPlayer().useAbilityCard(AbilityCard(reversE))) {
        std::cout << game_state.getCurrentPlayer().getName() << " melakukan REVERSE" << std::endl;
        std::cout << "Urutan eksekusi giliran ini : ";
        printQueue(game_state.getQueue());

        reversE.consume();
        std::cout << std::endl << "Urutan eksekusi giliran selanjutnya : ";
        printQueue(game_state.getQueue());
        std::cout << std::endl;
    }
    else {
        std::cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability REVERSE.";
    }
}

void GameIO::printQueue(std::vector<Player*> queue) {
    /* int size = queue.size();
    for (int i = 0; i < size; i++) {
        Player *temp = queue.at(i);
        std::cout << *temp.getName() << " ";
    } */
}

void GameIO::swapCardIO(GameState& game_state) {
    SwapCard swapcard(game_state);
    if (game_state.getCurrentPlayer().useAbilityCard(AbilityCard(swapcard))) {
        std::cout << game_state.getCurrentPlayer().getName() << " melakukan SWAPCARD" << std::endl;

        int firstTargetId = firstSwapTarget(game_state.getCurrentPlayer(), game_state.getPlayerList());
        int secondTargetId = secondSwapTarget(game_state.getCurrentPlayer(), firstTargetId, game_state.getPlayerList());
        
        int firstCard = firstSwapCard(game_state.getPlayerById(firstTargetId));
        int secondCard = secondSwapCard(game_state.getPlayerById(secondTargetId));

        swapcard.setTarget(firstTargetId, secondTargetId, firstCard-1, secondCard-1);
        swapcard.consume();
    }
    else {
        std::cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability SWAPCARD." << std::endl;
    }
}

int GameIO::firstSwapTarget(Player player, std::vector<Player> player_list) {
    std::cout << "Silahkan pilih pemain yang kartunya ingin anda tukar: " << std::endl;
    std::vector <std::pair<int, Player>> target_list;   
    int i = 1;
    for (int j = 0; j < 7; j++) {
        if (player_list.at(j).getPlayerId() != player.getPlayerId()) {
            target_list.push_back(std::make_pair(i, player_list.at(j)));
            i++;
        }
    }

    for (int k = 0; k < 6; k++) {
        std::cout << target_list.at(k).first << ". " << target_list.at(k).second.getName() << std::endl;
    }

    int target;
    std::cin >> target;

    return target_list.at(target-1).second.getPlayerId();
}

int GameIO::secondSwapTarget(Player player, int first_id, std::vector<Player> player_list) {
    std::cout << "Silahkan pilih pemain lain yang kartunya ingin anda tukar: " << std::endl;
    std::vector <std::pair<int, Player>> target_list;   
    int i = 1;
    for (int j = 0; j < 7; j++) {
        if (player_list.at(j).getPlayerId() != player.getPlayerId() && player_list.at(j).getPlayerId() != first_id) {
            target_list.push_back(std::make_pair(i, player_list.at(j)));
            i++;
        }
    }

    for (int k = 0; k < 5; k++) {
        std::cout << target_list.at(k).first << ". " << target_list.at(k).second.getName() << std::endl;
    }

    int target;
    std::cin >> target;

    return target_list.at(target-1).second.getPlayerId();
}

int GameIO::firstSwapCard(Player first_player) {
    std::cout << "Silahkan pilih kartu kanan/kiri " << first_player.getName() << std::endl;
    std::cout << "1. Kanan" << std::endl;
    std::cout << "2. Kiri" << std::endl;

    int target;
    std::cin >> target;

    return target; 
}

int GameIO::secondSwapCard(Player second_player) {
    std::cout << "Silahkan pilih kartu kanan/kiri " << second_player.getName() << std::endl;
    std::cout << "1. Kanan" << std::endl;
    std::cout << "2. Kiri" << std::endl;

    int target;
    std::cin >> target;

    return target; 
}

void GameIO::switchIO(GameState& game_state) {
    Switch switcH(game_state);
    if (game_state.getCurrentPlayer().useAbilityCard(AbilityCard(switcH))) {
        std::cout << game_state.getCurrentPlayer().getName() << " melakukan SWITCH" << std::endl;

        PlayerCard firstCard = game_state.getCurrentPlayer().getItemAt(0);
        PlayerCard secondCard = game_state.getCurrentPlayer().getItemAt(1);

        std::cout << "Kartumu sekarang adalah :" << std::endl;
        std::cout << firstCard.getNumber() << " (" << firstCard.getColor() << ") && " << secondCard.getNumber() << " (" << secondCard.getColor() << ")" << std::endl;

        int targetId = firstSwapTarget(game_state.getCurrentPlayer(), game_state.getPlayerList());

        switcH.setTarget(targetId);
        switcH.consume();

        std::cout << "Kedua kartu " << game_state.getCurrentPlayer().getName() << " telah ditukar dengan " << game_state.getPlayerById(targetId).getName() << "!" << std::endl;

        firstCard = game_state.getCurrentPlayer().getItemAt(0);
        secondCard = game_state.getCurrentPlayer().getItemAt(1);

        std::cout << "Kartumu sekarang adalah :" << std::endl;
        std::cout << firstCard.getNumber() << " (" << firstCard.getColor() << ") && " << secondCard.getNumber() << " (" << secondCard.getColor() << ")" << std::endl;   
    }
    else {
        std::cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability SWITCH.";
    }
}

void GameIO::abilitylessIO(GameState& game_state) {
    Abilityless abilityless(game_state);
    if (game_state.getCurrentPlayer().useAbilityCard(AbilityCard(abilityless))) {
        int targetId = targetAbilityless(game_state.getCurrentPlayer(), game_state.getPlayerList());
    } 
    else {
        std::cout << "Ets, tidak bisa. Kamu tidak punya kartu Ability ABILITYLESS.";
    }
}

bool GameIO::checkNoAbilty(Player player, std::vector<Player> player_list) {
    /* bool noOne = true;
    for (int i = 0; i < 7; i++) {
        if (player_list.at(i).getPlayerId() != player.getPlayerId()) {

        } 
    } */
}

int GameIO::targetAbilityless(Player player, std::vector<Player> player_list) {
    std::cout << player.getName() << " akan mematikan kartu ability lawan!" << std::endl;
    std::cout << "Silahkan pilih pemain yang kartu abilitynya ingin dimatikan:" << std::endl;

    std::vector <std::pair<int, Player>> target_list;   
    int i = 1;
    for (int j = 0; j < 7; j++) {
        if (player_list.at(j).getPlayerId() != player.getPlayerId()) {
            target_list.push_back(std::make_pair(i, player_list[j]));
            i++;
        }
    }

    for (int k = 0; k < 6; k++) {
        std::cout << target_list.at(k).first << ". " << target_list.at(k).second.getName() << std::endl;
    }

    int target;
    std::cin >> target;

    return target_list.at(target-1).second.getPlayerId();
}
