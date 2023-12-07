#include "../include/Inventory.hpp"

string Inventory::getInventoryContents() const {
    string outputString = "";
    int listNum = 1;

    for (unsigned i = 0; i < items.size(); ++i) {
        outputString += to_string(listNum) + ". " + items.at(i)->getName() + "\n";
        ++listNum;
    }

    return outputString;
}

string Inventory::getItemDescription(int itemIndex) const {
    if (!(0 <= itemIndex && itemIndex < items.size())) {
        throw runtime_error("Cannot get item description. Index is out of range.");
    }
    return items.at(itemIndex)->getDescription();
}

void Inventory::addItem(inventoryObject* newItem) {
    items.push_back(newItem);
}

int Inventory::itemCount() const {
    return items.size();
}