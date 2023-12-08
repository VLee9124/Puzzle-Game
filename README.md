# Puzzle Room 
Authors: [Benedict Ignacio](https://github.com/Benedict-Ignacio), [Victor Lee](https://github.com/VLee9124), [Marcos Vasquez-Munoz](https://github.com/Marcos4440), [Christopher Hakker](https://github.com/chris-hakker)

## Project Description
Synopsis: Our project will be a text-based puzzle RPG similar to that of an escape room. Here, players are given clues and have to solve a series of riddles and questions in order to progress through the story and ultimately escape the room and/or reach the good ending of the game.

Purpose: We found this concept interesting because as computer science students, we’ve always had confidence in our problem solving skills. Although our main purpose of this program is to entertain users, we want to do so by tapping into their own problem solving abilities, and creating puzzles/mysteries are one of the most entertaining and thrilling methods of doing so. We wanted to take this a step further and incorporate an “escape room” aspect to our program, where the order of puzzles that we have to solve is intentionally obscured to give players a sense of wonder and mystery.

Tools/Languages: We will use the following tools to assist with development:
* C++ language and standard libraries
* VSCode as main IDE
* Github for version tracking
* CMake for generating build files

Input/Output: All of the necessary user input and output will be done on the terminal.
* Input - Our program will require users to do the following directly onto the terminal:
   * Choose from a list of options (e.g. choosing a number from 1 to 5)
   * Enter characters to open settings (e.g. pressing ‘I’ to open the inventory)
   * Enter strings/text (e.g. entering a passcode)
* Output - The user will be able to read the following directly from terminal output:
   * General User Interface (e.g. users will be reminded of which button to press to open the inventory system)
   * Text Dialogue (e.g. reading a note will bring up the following text onto the terminal, which may be used for a clue to another puzzle)
   * Scene Dialogue (e.g. users will be given feedback immediately after they’ve performed a certain action)

Features: The following lists will describe all our planned features, from most to least important:
* Menu System - The user interface that will be used to interact with the game’s puzzles
* Inventory System - Users will input a character onto the menu system to immediately open the inventory system, where they will interact with the items they’ve already collected from the room
* Puzzles - These are the main obstacles of the game. They lock the player from progressing past them (e.g. locked chest, locked door) unless they can solve the puzzle. Examples of puzzles include finding a key to open a keylock and finding a certain combination to enter on a keypad.

## User Interface Specification

### Navigation Diagram

The following image represents the user experience as they go through the Puzzle Room program:

<img width="4924" alt="Navigation Diagram (1)" src="https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/111732595/60478b87-25ee-4768-ac8f-0357b26c6d0d">

The player will start off in the Main Game Screen. Once they start the game, the program creates a Player object that contains an inventory system and keeps track of the current room that they are in. The program also builds the game map, which is a collection of interconnected rooms. The program will then tell the user what room they are currently in, as well as how to use the player controls. The main screen contains three major functionalities: Inventory, Move Room, and Examine Room.

The Inventory screen will allow the user to keep track of and observe all the items they've collected so far in their inventory.

The Examine Room screens will allow the user to observe, interact with, and/or collect any items in the current room that they are in.

The Move Room screen will allow the user to choose which room to switch to, provided that the passage to the adjacent room is unlocked.

If the program detects that the player's current room is the EXIT room, the user is taken to the Victory Screen, and the game is complete. The program finishes.

### Screen Layouts

#### Main Menu

Every line that requires user input will start with >. Every user input will be represented in chars. Also, if at any point an invalid character is entered, the program doesn’t proceed until a valid character is read.

#### Main Screen

<img width="60%" height="60%" alt="Main Interface" src="https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/111732595/40598ea9-c448-4e25-a9c5-104be0addfa4">

This is the main interface that the user will interact with during the game. The screen outputs the room name and description that the player is in. 

Then, they are tasked to enter F to examine, I to open their inventory, and M to move to a different room. The player can also quit at any time.

#### Examine Room

<img width="60%" height="60%" alt="Examine Room" src="https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/111732595/6519200e-f582-4fa1-99f0-fad849c6e679">

Players will be taken to this screen after they input F back at the main screen. They are given a list of all the object names in the current room and are tasked to enter a number or quit. 

Once a valid number is inputted, the program returns that respective object’s observation as a string, then performs an interaction specific to the type of object it is.

#### Inventory

<img width="60%" height="60%" alt="Main Menu" src="https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/111732595/315e0b6c-a871-467c-aa97-8aa6258fdbda">

The player will be taken to this screen after entering I in the main interface. Here, the player will be given a list of all the object names in their inventory and are tasked to choose which one to observe, or to quit.

If the user enters a valid number, the program will return the specified object’s observation as a string. Continue taking user input until Q is read.

#### Move Room
<img width="60%" height="60%" alt="Main Menu" src="https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/111732595/36d5fbcd-ca49-4315-8775-ad3d00f25ac8">

After the user enters M in the main interface, they are taken to this screen, where they will be given a list of rooms that are adjacent to the one the player is in right now. The user is tasked to enter a number to move to its respective room.

The program will tell the user if the move was successful. If it is, the current room is reassigned. Otherwise, keep the user in the room they were in initially.

#### Victory

<img width="60%" height="60%" alt="Main Menu" src="https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/111732595/1c312a4f-b02c-40aa-abb0-6bd25e77901e">

Once the program detects if the player is in the EXIT room, the program will switch to the victory screen. The player has to simply enter any key to complete the game and return to the main menu.

## Class Diagram

The following diagram showcases the main classes that will be used in the project:

<img width="100%" height="100%" alt="Class Diagram" src="https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/111732595/1b7674db-54e4-4383-84ea-45204d0f6c62">

GameTerminal: This class serves as the control class that handles game flow. It is responsible for I/O throughout the entirety of the program.

Player: This will keep track of what room the player is currently at inside the map, while also managing an inventory system.

Inventory: This class, which can only be used by a Player, manages a collection of GameObjects that the user can keep track of as they traverse through the map. There can be as many or as little GameObjects in Inventory.

Room: This class will largely make up the map of the program. The user will have to traverse through different rooms in order to successfully finish the game.

GameObject: These are essentially the building blocks to the puzzle element in our program. GameObjects are anything that can be observed/interacted by the user to help communicate clues. Many of our GameObjects will be contained inside rooms.

InventoryObject: These are special GameObjects that can be taken from a room and collected by the player to store inside of their inventory.

Door: Doors are a special type of GameObject that contain a pointer to another room. These serve as the main methods of player movement in the game.

LockedObject: These special objects cannot be interacted with unless the user can solve their associated puzzle that will unlock upon completion.

LockedDoor: Derived from both Door and LockedObject, the user cannot interact with or access its adjacent door unless they complete their associated puzzle.

Puzzle: Puzzles are the main obstacles that will block player progress during the game. Keep in mind that this generic Puzzle class is abstract, and different types of Puzzles will derive from it.

KeypadPuzzle: This is a type of Puzzle that requires the user to enter a numeric passcode in order to solve it.

Overall, this diagram represents the fundamental classes and mechanisms that will help our program function. Player, Inventory, Room, GameObject, and Puzzle all serve as the core part of our project. This comprehensive list and diagram may be updated to reflect additional classes that may be implemented, such as other kinds of Puzzles and GameObjects.

### Updating class diagram with SOLID principles
For reference, our old class diagram can be found here:

<img width="100%" height="100%" alt="Class Diagram" src="https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/111732595/81e55e41-17bd-425a-9f9e-07575ea0a01b">

* 2023/11/13: We found that the original GameObject class had violated the Interface Segregation Principle, as well as the Single Responsibility Principle. This is because GameObject had functions checking if the object was collectable, when all that GameObject needs are the appropriate getters/setters and a general interact() function. This makes GameObject have two responsibilities, and checkIfCollectable() only applies to some special objects. Thus, we created a separate interface for InventoryObjects that only have to deal with collection. This way, we don't have to implement the collection functions for all subtypes, making code maintenance easier for GameObjects.
* 2023/11/14: We realized that Door violates the Single Responsibility Priniciple since it has two tasks - checking if the door is locked and getting the adjacent room. Thus, we created another subtype of GameObject called LockedObject that will deal with any object that is locked. Door now doesn't have a checkIfLocked() function anymore, and we also updated the LockedDoor class to extend from both Door and LockedObject. Because of this change, Door class is more stable and easily defined, and we can also create non-Door objects that can also be locked, making the locked feature more applicable.
* 2023/11/15: The Player class had violated the Single Responsibility Principle since it tried to be an entity that controls the current room, as well as an interface that outputs the "screens" at the same time. To solve this, the outputting responsibility will be done by a different class called GameTerminal, which fully manages the game loop. This way, Player just has to deal with keeping track of the current room, and we also separate our I/O classes from the rest of our program, which makes our code more readable and easier to maintain.
* 2023/11/21: We realized that because the data members of every class were either protected or private, there wasn't a way for the classes to communicate with each other. Thus, we added setters and getters for most of our classes, as well as extra functionality for classes such as Inventory to increase the amount of information that Player (and by extension, GameTerminal) can access. This change was made in response to TA feedback after Phase II.
* 2023/12/7: We cleaned up the class diagram to make it reflect our actual implementation. All the classes, functions, parameters, and return types should be the same as mentioned in the hpp files.
 
 ## Screenshots
![screenshot1](https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/111732595/a634edc0-d558-4901-877d-a0c58e7f343a)
![screenshot2](https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/111732595/1f763b0d-7912-4f11-95ad-16c8ab76c8a5)
![screenshot3](https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/111732595/cafd4cd5-8782-4aed-a0a0-5429409708fc)
![screenshot4](https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/111732595/12556f36-aada-44f3-9a10-e3f3d2ee2c83)
![screenshot5](https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/111732595/531b5b03-7bbb-4298-8eda-712aae537088)
![screenshot6](https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/111732595/db752ed9-18e4-40bf-9bfb-d9d2f702ee51)
![screenshot7](https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/111732595/33932043-8437-4df0-86fe-73f76b10114c)
![screenshot8](https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/111732595/bf345437-cd1b-4cac-91de-879fce52858d)

 ## Installation/Usage
 There are 2 ways to install this program. You can either build the project into an executable or run the output files as is. 
 
 ### Building the executable
 The installation assumes that CMake are already installed on the system.
 
 If you want to build the project into a executable:
 1. Clone the repository
 2. `cd` into local repository
 3. Build the project by using `cmake .`
 4. Run `cpack --config CPackConfig.cmake` and `cpack --config CPackSourceConfig.cmake` to build the source and executables.
 5. Run executable that is generated (.sh, .exe, etc.)
 
 ### Installation
 The installation assumes that CMake and Make are already installed on the system. 
 
 To build and install the game:
 1. Clone the repository to your local machine
 2. `cd` into local repository
 3. Build the project by using `cmake .` and then `make`
 4. Run the game executable `./bin/PuzzleGame`

 ## Testing
 We used GoogleTests to verify that our functions and classes work as planned. Below are screenshots of all the unit tests that we wrote.
 
![test1](https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/111732595/c3c7d0da-9a84-4f68-808e-9adc39ecc95d)
![test2](https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/111732595/35516dd2-273e-4457-8ea8-82d6ac1e471d)
![test3](https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/111732595/078259cf-6a4b-4fde-a0c9-25998fb4a471)
![test4](https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/111732595/0fbca2e5-e9bd-40a5-8a81-a6bd3ff752a7)
![test5](https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/111732595/fbabc4fb-583c-496a-a09c-ad33264660c5)
![test6](https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/111732595/148408c8-49e6-42ee-8089-8e9eabb9a2dd)

