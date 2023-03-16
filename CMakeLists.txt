cmake_minimum_required(VERSION 3.24)
project(IF2210_Pemrograman_Berorientasi_Objek)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mrdrnd")
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++ -static")

include_directories(src/ability)
include_directories(src/ability/headers)
include_directories(src/cards)
include_directories(src/cards/headers)
include_directories(src/game)
include_directories(src/game/headers)
include_directories(src/io)
include_directories(src/io/headers)
include_directories(src/inventory)
include_directories(src/inventory/headers)
include_directories(src/player)
include_directories(src/player/headers)
include_directories(src/exceptions)
include_directories(src/exceptions/headers)
include_directories(src/util)

add_executable(IF2210_Pemrograman_Berorientasi_Objek
        src/ability/headers/ability.hpp src/ability/ability.cpp
        src/cards/headers/cards.hpp src/cards/cards.cpp
        src/cards/headers/combo.hpp src/cards/combo.cpp
        src/cards/headers/hand.hpp
        src/exceptions/headers/generalexceptions.hpp
        src/game/headers/gamestate.hpp src/game/gamestate.cpp
        src/inventory/headers/inventory.hpp src/inventory/inventory.cpp
        src/inventory/headers/limitedinventory.hpp src/inventory/limitedinventory.cpp
        src/inventory/headers/playerinventory.hpp src/inventory/playerinventory.cpp
        src/io/headers/gameio.hpp
        src/player/headers/inventoryHolder.hpp
        src/player/headers/player.hpp src/player/player.cpp
        src/player/headers/tableCards.hpp src/player/tableCards.cpp
        src/main.cpp src/random.hpp src/io/gameio.cpp src/inventory/headers/deckinventory.hpp
        src/inventory/deckinventory.cpp
        src/player/headers/deckCard.hpp src/player/deckCard.cpp
        src/util/util.hpp)
