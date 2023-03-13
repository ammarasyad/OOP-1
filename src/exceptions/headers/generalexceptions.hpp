#ifndef IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_GENERALEXCEPTIONS_HPP
#define IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_GENERALEXCEPTIONS_HPP

#include <exception>
#include <string>

class GameStateException: public std::exception {
private:
    const char* message;
public:
    explicit GameStateException(const std::string& message): message(message.c_str()) {}
    const char* what() const noexcept override {
        return message;
    }
};

#endif //IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_GENERALEXCEPTIONS_HPP
