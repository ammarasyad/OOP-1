#ifndef IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_GENERALEXCEPTIONS_HPP
#define IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_GENERALEXCEPTIONS_HPP

#include <exception>
#include <string>

class GameStateException: public std::exception {
private:
    char* message;
public:
    explicit GameStateException(char* message): message(message) {}
    const char* what() const noexcept {
        return message;
    }
};

#endif //IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_GENERALEXCEPTIONS_HPP
