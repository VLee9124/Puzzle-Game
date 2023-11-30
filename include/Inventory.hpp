#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <iostream>
#include <vector>
#include <string>
#include "inventoryObject.h"
using namespace std;

class Inventory {
    public:
        Inventory() {}
        void addItem(inventoryObject* newItem);

        string getInventoryContents() const;
        string getItemDescription(int) const;
        int itemCount() const;
    private:
        vector<inventoryObject*> items;
};

#endif