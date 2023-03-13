#ifndef IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_LIMITEDINVENTORY_HPP
#define IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_LIMITEDINVENTORY_HPP

#include "inventoryholder.hpp"

class LimitedInventory: public InventoryHolder {
private:
    int limit;
public:
    LimitedInventory();
    explicit LimitedInventory(int);
    void addToDeck(PlayerCard&);
    std::vector<PlayerCard>& operator+(PlayerCard& card);
    friend vector<PlayerCard>& operator+(PlayerCard&, LimitedInventory&);

};

#endif //IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_LIMITEDINVENTORY_HPP
