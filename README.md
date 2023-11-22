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

<img width="80%" alt="Navigation Diagram" src="https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/86755705/f2836463-6801-4e44-9c00-7de6994811f1">

The player will start off in the Main Menu. Once they start the game, the program creates a Player object that contains an inventory system and keeps track of the current room that they are in. The program also builds the game map, which is a collection of interconnected rooms. The user is then sent to the Main Interface. Here, the program will tell the user what room they are currently in, as well as how to use the player controls. The interface contains three major functionalities: Inventory, Move Room, and Examine Room.

The Inventory screen will allow the user to keep track of and observe all the items they've collected so far in their inventory.

The Examine Room screens will allow the user to observe, interact with, and/or collect any items in the current room that they are in.

The Move Room screen will allow the user to choose which room to switch to, provided that the passage to the adjacent room is unlocked.

If the program detects that the player's current room is the EXIT room, the user is taken to the Victory Screen, and the game is complete. They can return to the main menu, and the map will reset. 

### Screen Layouts

#### Main Menu
<img width="60%" height="60%" alt="Main Menu" src="https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/86755705/eb3aaef3-dab9-44f4-807d-c18f60645c7b">

This is the first screen that the user sees when starting the program. After the game welcomes you, you are tasked to either enter S or Q to start or quit the game. 

Every line that requires user input will start with >. Every user input will be represented in chars. Also, if at any point an invalid character is entered, the program doesn’t proceed until a valid character is read.

#### Main Interface
<img width="60%" height="60%" alt="Main Interface" src="https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/86755705/f75f680e-2559-44e8-97e3-e572f9ee114e">

This is the main interface that the user will interact with during the game. The screen outputs the room name and description that the player is in. 

Then, they are tasked to enter F to examine, I to open their inventory, and M to move to a different room. The player can also quit at any time.

#### Examine Room
<img width="60%" height="60%" alt="Examine Room" src="https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/86755705/d8d31297-7267-4eea-b096-736a4146fac0">

Players will be taken to this screen after they input F back at the main interface. They are given a list of all the object names in the current room and are tasked to enter a number or quit. 

Once a valid number is inputted, the program returns that respective object’s observation as a string. 

Then, if the object is interactable OR can be collected, proceed to Ask To Interact and/or Ask to Take From Room screens.

The player will only be taken back to the main interface if they enter Q.

##### Ask To Interact
<img width="60%" height="60%" alt="Main Menu" src="https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/86755705/1c05d59c-118e-4e64-99c9-18b2a8a6c6dd">

If the object is interactable, the program asks if the user wants to interact with the specified object, and the player has a choice to enter Y to accept or N to decline. 

If the user accepts, the program returns the object’s interaction as a string output.

##### Ask To Take From Room
<img width="60%" height="60%" alt="Main Menu" src="https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/86755705/8ae521de-d286-44e1-a988-6514e4f85e6f">

If the object can be collected by the player, the program asks if they want to do so using Y or N. 

If so, the program removes the object from the room and adds it into the player’s inventory.

#### Inventory
<img width="60%" height="60%" alt="Main Menu" src="https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/86755705/0b455dcc-9a5d-40d2-8c55-332306e4db0e">

The player will be taken to this screen after entering I in the main interface. Here, the player will be given a list of all the object names in their inventory and are tasked to choose which one to observe, or to quit.

If the user enters a valid number, the program will return the specified object’s observation as a string. Continue taking user input until Q is read.

#### Move Room
<img width="60%" height="60%" alt="Main Menu" src="https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/86755705/28fa9c9f-bbe9-4e43-a888-1651c5e0293a">

After the user enters M in the main interface, they are taken to this screen, where they will be given a list of rooms that are adjacent to the one the player is in right now. The user is tasked to enter a number to move to its respective room.

The program will tell the user if the move was successful. If it is, the current room is reassigned. Otherwise, keep the user in the room they were in initially.

#### Victory
<img width="60%" height="60%" alt="Main Menu" src="https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/86755705/82b49e95-3f96-4695-9cd3-370e4345e2c1">

Once the program detects if the player is in the EXIT room, the program will switch to the victory screen. The player has to simply enter S to complete the game and return to the main menu.

## Class Diagram

The following diagram showcases the main classes that will be used in the project:

<img width="100%" height="100%" alt="Class Diagram" src="https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/111732595/1a687538-e389-460a-bbca-f222c5647ecc">

GameTerminal: This class is the main control class that the user will interact with throughout the course of the game. These specify the "screens" described in the navigation diagram, including the main interface, move room, inventory, examine room, and win screen.

Player: This class is an entity that keeps track of what room the player is currently at inside the game, while also managing an inventory system.

Inventory: This class, which can only be used by a Player, manages a collection of GameObjects that the user can keep track of as they traverse through the map. There can be as many or as little GameObjects in Inventory, but the relationship between the inventory system and the Player is 1 to 1.

Room: This class will largely make up the map of the program. They essentially act as the map's "nodes" that contain GameObjects, as well as doors that connect different rooms together. The user will have to traverse through different rooms in order to successfully finish the game.

GameObject: These are essentially the building blocks to the puzzle element in our program. GameObjects are anything that can be observed/interacted by the player. They may provide clues or solutions, but they can also serve as obstacles to the player. GameObjects also have the ability to be modified/interacted with by the user so that new information can be extracted from it. Many of our GameObjects will be contained inside rooms.

InventoryObject: These are special GameObjects that can be taken from a room and collected by the player to store inside of their inventory.

Door: Doors are a special type of GameObject that contain a pointer to another room. These types of doors are unlocked by default. These serve as the main methods of player movement in the game.

LockedObject: These special objects cannot be interacted with unless the user can solve their associated puzzle that will unlock upon completion.

LockedDoor: Derived from both Door and LockedObject, the user cannot interact with or access its adjacent door unless they complete their associated puzzle.

Puzzle: Puzzles are the main obstacles that will block player progress during the game. They can be affixed to GameObjects, particularly PuzzleDoors, so that the player cannot interact or unlock the object unless they complete its puzzle. Keep in mind that this generic Puzzle class is abstract, and different types of Puzzles will derive from it.

KeypadPuzzle: This is a type of Puzzle that requires the user to enter a numeric passcode in order to solve it.

Overall, this diagram represents the fundamental classes and mechanisms that will help our program function. Player, Inventory, Room, GameObject, and Puzzle all serve as the core part of our project. This comprehensive list and diagram may be updated to reflect additional classes that may be implemented, such as other kinds of Puzzles and GameObjects.

### Updates To Class Diagram
For reference, the old class diagram is showcased below:

<img width="100%" height="100%" alt="Class Diagram" src="https://github.com/cs100/final-project-vlee084-bigna003-chakk001-mvasq094/assets/111732595/834755d3-4fd2-4898-a377-37f8b931c3cf">

* 2023/11/13: We found that the original GameObject class had violated the Interface Segregation Principle, as well as the Single Responsibility Principle. This is because GameObject had functions checking if the object was collectable, when all that GameObject needs are the appropriate getters/setters and a general interact() function. This makes GameObject have two responsibilities, and checkIfCollectable() only applies to some special objects. Thus, we created a separate interface for InventoryObjects that only have to deal with collection. This way, we don't have to implement the collection functions for all subtypes, making code maintenance easier for GameObjects.
* 2023/11/14: We realized that Door violates the Single Responsibility Priniciple since it has two tasks - checking if the door is locked and getting the adjacent room. Thus, we created another subtype of GameObject called LockedObject that will deal with any object that is locked. Door now doesn't have a checkIfLocked() function anymore, and we also updated the LockedDoor class to extend from both Door and LockedObject. Because of this change, Door class is more stable and easily defined, and we can also create non-Door objects that can also be locked, making the locked feature more applicable.
* 2023/11/15: The Player class had violated the Single Responsibility Principle since it tried to be an entity that controls the current room, as well as an interface that outputs the "screens" at the same time. To solve this, the outputting responsibility will be done by a different class called GameTerminal, which fully manages the game loop. This way, Player just has to deal with keeping track of the current room, and we also separate our I/O classes from the rest of our program, which makes our code more readable and easier to maintain.
* 2023/11/21: We realized that because the data members of every class were either protected or private, there wasn't a way for the classes to communicate with each other. Thus, we added setters and getters for most of our classes, as well as extra functionality for classes such as Inventory to increase the amount of information that Player (and by extension, GameTerminal) can access. This change was made in response to TA feedback after Phase II.

 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on Zoom and should be conducted by Wednesday of week 8.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
