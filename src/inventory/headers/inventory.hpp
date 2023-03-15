#ifndef IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_INVENTORY_HPP
#define IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_INVENTORY_HPP

#include <vector>

template <class T>
class Inventory {
    protected:
        std::vector<T> deck;
        int deckSize;
    public:
        Inventory();

        virtual void addToDeck(T&);
        T& at(int) const;
        int getDeckSize() const;

        /*
         * this function switch elements between vector v1 and v2 with index indices[i][0] (v1) and index
         * indices[i][1] (v2)
         *
         * */
        static void
        switchElements(Inventory<T> &inv1, Inventory<T> &inv2, std::vector<std::pair<int, int>> &indices);

        virtual bool operator==(Inventory<T>&);

};

#endif //IF2210_PEMROGRAMAN_BERORIENTASI_OBJEK_INVENTORY_HPP
