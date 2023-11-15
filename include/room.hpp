#ifndef ROOM_HPP
#define ROOM_HPP

class Room {
    private:
        vector<gameObject*> objectList;
        vector<Door*> doorList;
        string roomName;
        string roomDesc;
    public:
        Room(string name);
        string getAdjacentRooms();
        string getAllObjects();
        string getDesc();
        string getName();
        void removeObject(GameObject* targetObj);
        void addObject(GameObject* newObj);
        void addDoor(Door* newDoor);
};

#endif /* ROOM_HPP */