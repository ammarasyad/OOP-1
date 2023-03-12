cmake_minimum_required(VERSION 3.24)
project(IF2210_Pemrograman_Berorientasi_Objek)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/cards)
include_directories(src/game)
include_directories(src/game/headers)
include_directories(src/io)
include_directories(src/io/headers)
include_directories(src/player)
include_directories(src/player/headers)
include_directories(src/exceptions)
include_directories(src/exceptions/headers)

add_executable(IF2210_Pemrograman_Berorientasi_Objek
        src/cards/cards.cpp
        src/cards/cards.hpp
        src/cards/combo.cpp
        src/cards/combo.hpp
        src/cards/hand.hpp
        src/game/headers/gamestate.hpp
        src/io/headers/gameio.hpp
        src/player/headers/player.hpp
        src/main.cpp src/game/gamestate.cpp src/exceptions/headers/generalexceptions.hpp)
