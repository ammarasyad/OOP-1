#ifndef IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_LIMITEDINVENTORY_HPP
#define IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_LIMITEDINVENTORY_HPP

#include "inventory.hpp"

template <class T>
class LimitedInventory: public Inventory<T> {
private:
    int limit;
public:
    LimitedInventory();
    explicit LimitedInventory(int);
    void addToDeck(T&);
    std::vector<T>& operator+(T& card);
    friend vector<T>& operator+(T&, LimitedInventory&);

};

#endif //IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_LIMITEDINVENTORY_HPP
