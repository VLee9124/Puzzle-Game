#include "Player.h"

Player::Player(Room* startRoom) : currRoom(startRoom) {
}

void Player::setCurrRoom(Room* newRoom) {
    currRoom = newRoom;
}

Room* Player::getCurrRoom() const {
    return currRoom;
}

Inventory& Player::getInventory() {
    return playerInventory;
}
