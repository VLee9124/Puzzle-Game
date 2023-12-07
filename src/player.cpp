#include "../include/Player.h"

Player::Player() : currRoom(nullptr) {}

Player::Player(Room* startRoom) : currRoom(startRoom) {}

void Player::setCurrRoom(Room* newRoom) {
    currRoom = newRoom;
}

Room* Player::getCurrRoom() const {
    return currRoom;
}

inventory& Player::getInventory() {
    return playerInventory;
}
