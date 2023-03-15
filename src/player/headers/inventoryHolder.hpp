#ifndef INVENTORY_HOLDER_HPP
#define INVENTORY_HOLDER_HPP


#include <iostream>
#include "limitedinventory.hpp"

template <class T, class U>
class InventoryHolder {
    protected:
        T inventory_;
    public:
        virtual T getInventory() const = 0;
        virtual void setInventory(T) = 0;

        virtual void addItem(U) = 0;
        virtual void removeItem(U) = 0;
        
        virtual U getItemAt(int) const = 0;

        virtual void reset() = 0;
};



#endif