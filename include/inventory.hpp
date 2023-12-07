#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "inventoryObject.h"
using namespace std;

class inventory {
    public:
        inventory() {}
        ~inventory();

        // Mutators
        void addItem(inventoryObject* newItem);
        void removeItem(int);

        // Accessors
        inventoryObject* getItemFromInventory(int) const;
        vector<inventoryObject*> getInventoryContents() const;
        string getItemDescription(int) const;

        // Helper function
        int itemCount() const;
    private:
        vector<inventoryObject*> items;
};