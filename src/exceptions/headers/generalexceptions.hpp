#ifndef IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_GENERALEXCEPTIONS_HPP
#define IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_GENERALEXCEPTIONS_HPP

#include <exception>
#include <string>
#include <utility>

class GameStateException: public std::exception {
private:
    const std::string message;
public:
    explicit GameStateException(std::string message): message(std::move(message)) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class InventoryException: public std::exception {
private:
    const std::string message;
public:
    explicit InventoryException(std::string message): message(std::move(message)) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};


class PlayerException: public std::exception {
private:
    const std::string message;
public:
    explicit PlayerException(std::string message): message(std::move(message)) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class UtilException: public std::exception {
private:
    const std::string message;
public:
    explicit UtilException(std::string message): message(std::move(message)) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif //IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_GENERALEXCEPTIONS_HPP
