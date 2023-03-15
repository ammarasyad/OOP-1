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
    LimitedInventory<T>& operator+(T& card);
    friend LimitedInventory<T>& operator+(T&, LimitedInventory&);
    LimitedInventory<T>& operator-(T& card);
    friend LimitedInventory<T>& operator-(T&, LimitedInventory&);
    /*
     * this function switch elements between vector v1 and v2 with index indices[i][0] (v1) and index
     * indices[i][1] (v2)
     * */
    static std::pair<std::vector<T>&, std::vector<T>&>
            switchCards(std::vector<T> &v1, std::vector<T> &v2, std::vector<std::pair<int, int>> &indices);

};


#endif //IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_LIMITEDINVENTORY_HPP
