#include <iostream>
#include <vector>
#include <string>
#include "../include/gameTerminal.hpp"

int main() {
    vector<Room*> mapOne;

    Room* room1 = new Room("Hallway", "You are in the hallway of the complex. There seems to be a lot of doors leading to different rooms. The exit at the far end of the corner.");
    Room* room2 = new Room("Bedroom", "You are in a fairly sparse bedroom with nothing but a bed and a few items scattered on the floor.");
    Room* room3 = new Room("Study Room", "You are in a study room. It seems the person who was last here kept the place fairly tidy.");
    Room* end = new Room("End Room", "N/A");
    
    mapOne.push_back(room1);
    mapOne.push_back(room2);
    mapOne.push_back(room3);
    mapOne.push_back(end);

    room1->addDoor(new Door("Left Door", "You observe a closed door that seems to lead to a bedroom.", "After opening the door, you notice its room number '101'. It leads to a bedroom.", room2));
    room1->addDoor(new Door("Right Door", "You observe a closed door that leads to the study room.", "After opening the door, you notice its room number '102'. It leads to the study.", room3));
    room1->addDoor(new lockedDoor("Door to Escape", "You observe the closed glowing door. It seems to be the only way out of here.", "You open the door and light from the outside world fills the hallway. You're almost out of here.", new KeypadPuzzle("Enter a six digit number.", 381748), end));

    room2->addDoor(new Door("Door to Hallway", "The door leads back to the hallway.", "You notice something scribbled on this side of the door: 'I am Green. My neighbor at 102 holds the number.'", room1, true));
    room2->addObject(new gameObject("Bed", "A basic bed with teal-colored sheets. There seems to be something underneath the covers.", "You uncover the sheets and find a color pattern: Red, Blue, Green."));
    room2->addObject(new inventoryObject("Crumpled Note", "A crumpled piece of paper on the floor. It appears to have some markings on it.", "The note you collected reads: '8841'.", "You collected the note."));
    room2->addObject(new lockedObject("Locked Chest", "You observe a closed chest.", "After opening the chest, its inside reads: 'Blue = 9'.", new KeypadPuzzle("Enter a four digit number.", 8841)));

    room3->addDoor(new Door("Door to Hallway", "The door leads back to the hallway.", "You notice something scribbled on this side of the door: 'I am Two. My neighbor at 101 holds the color.'", room1, true));
    room3->addObject(new inventoryObject("Journal", "A tattered journal on a desk.", "The journal you collected reads: 'Red = 8'.", "You collected the journal."));
    room3->addObject(new gameObject("Suspicious Poster", "A seemingly innocuous poster of a cat. You feel that the cat is hiding something.", "Tearing the poster, the back reads: 'The primary colors are a clue to my secret safe.'"));
    room3->addObject(new lockedObject("Safe", "A tightly secured safe with three slots.", "After opening the safe, you find a note that reads: 'Code to Exit: 381748'.", new KeypadPuzzle("Enter a three digit number.", 892)));

    gameTerminal gt(mapOne);
    gt.playGame(cout, cin);
    return 0;
}