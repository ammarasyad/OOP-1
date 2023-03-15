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
    void removeFromDeck(T&);

    virtual LimitedInventory<T>& operator+(T& card);
    virtual LimitedInventory<T>& operator-(T& card);

    template<class U>
    friend LimitedInventory<U>& operator+(U&, LimitedInventory<U>&);

    template<class U>
    friend LimitedInventory<U>& operator-(U&, LimitedInventory<U>&);

};

#endif //IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_LIMITEDINVENTORY_HPP
