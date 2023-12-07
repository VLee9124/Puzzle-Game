#include <iostream>
#include <vector>
#include <string>
#include "../include/gameTerminal.hpp"

int main() {
    vector<Room*> mapOne;

    Room* room1 = new Room("Hallway", "You are in the hallway of the complex. There seems to be a lot of doors leading to different rooms. The exit at the far end of the corner.");
    Room* room2 = new Room("Bedroom", "You are in a fairly sparse bedroom with nothing but a bed and a crumpled note on the floor.");
    Room* end = new Room("End Room", "N/A");
    
    mapOne.push_back(room1);
    mapOne.push_back(room2);
    mapOne.push_back(end);

    room1->addDoor(new Door("Door to Bedroom", "You observe a closed door that seems to lead to a bedroom.", "After opening the door, you notice its room number '101'. It leads to a bedroom.", room2));
    room1->addDoor(new lockedDoor("Door to Escape", "You observe the closed glowing door. It seems to be the only way out of here.", "You open the door and light from the outside world fills the hallway. You're almost out of here.", new KeypadPuzzle("Enter a four digit number.", 1234), end));
    room2->addDoor(new Door("Door to Hallway", "The door leads back to the hallway.", "After opening the door to the hallway, you notice 'A928' scribbled on this side of the door.", room1, true));
    room2->addObject(new gameObject("Bed", "A basic bed with teal-colored sheets. There seems to be something underneath the covers.", "You uncover the sheets and find a color pattern: Red, Blue, Purple."));
    room2->addObject(new inventoryObject("Crumpled Note", "A crumpled piece of paper on the floor. It appears to have some markings on it.", "The note you collected reads '8841'.", "You collected the note."));
    room2->addObject(new lockedObject("Locked Chest", "You observe a closed chest.", "After opening the chest, its inside reads '1234'.", new KeypadPuzzle("Enter a four digit number.", 8841)));

    gameTerminal gt(mapOne);
    gt.playGame(cout, cin);
    return 0;
}