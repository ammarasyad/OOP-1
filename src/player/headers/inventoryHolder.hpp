#ifndef INVENTORY_HOLDER_HPP
#define INVENTORY_HOLDER_HPP


#include "playerinventory.hpp"
#include <iostream>

//temp
template <class T>
class Inventory {

};

template <class T>
class InventoryHolder {
    protected:
        Inventory<T> inventory_;
    public:
        virtual Inventory<T> getInventory() = 0;
        virtual void setInventory(Inventory<T>) = 0;

        virtual void addItem(T item) = 0;
        virtual void removeItem(Card card) = 0;
        
        virtual T getCardAt(int index) = 0;
};



#endif