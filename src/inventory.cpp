#include "../include/inventory.hpp"

// Destroy all items in inventory. Used as part of garbage collector.
inventory::~inventory() {
    for (unsigned i = 0; i < items.size(); ++i) {
        delete items.at(i);
    }
}

// Return a string that lists all the object names in the inventory
// string inventory::getInventoryContents() const {
//     string outputString = "";
//     int listNum = 1;

//     for (unsigned i = 0; i < items.size(); ++i) {
//         outputString += to_string(listNum) + ". " + items.at(i)->getName() + "\n";
//         ++listNum;
//     }

//     return outputString;
// }

vector<inventoryObject*> inventory::getInventoryContents() const {
    return items;
}

// Returns the item description for one particular object in the inventory
string inventory::getItemDescription(int itemIndex) const {
    if (!(0 <= itemIndex && itemIndex < items.size())) {
        throw runtime_error("Cannot get item description. Index is out of range.");
    }
    return items.at(itemIndex)->getDesc();
}

// Adds a new item to the inventory
void inventory::addItem(inventoryObject* newItem) {
    items.push_back(newItem);
    newItem->interact();
}

// Removes an item from the inventory given its index.
void inventory::removeItem(int itemIndex) {
    if (!(0 <= itemIndex && itemIndex < items.size())) {
        throw runtime_error("Cannot get item. Index is out of range.");
    }
    inventoryObject* victimObject = items.at(itemIndex);
    items.erase(items.begin() + itemIndex);
    delete victimObject;
}

// Returns the pointer to an object in the inventory. Useful if we need to use an item in the game.
inventoryObject* inventory::getItemFromInventory(int itemIndex) const {
    if (!(0 <= itemIndex && itemIndex < items.size())) {
        throw runtime_error("Cannot get item. Index is out of range.");
    }
    return items.at(itemIndex);
}

// Returns how many items are in the inventory right now
int inventory::itemCount() const {
    return items.size();
}