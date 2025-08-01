#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Room {
public:
    int roomNumber;
    bool isBooked;
    string customerName;

    Room(int number) {
        roomNumber = number;
        isBooked = false;
        customerName = "";
    }

    void bookRoom(string name) {
        if (!isBooked) {
            isBooked = true;
            customerName = name;
            cout << "Room " << roomNumber << " has been booked by " << customerName << ".\n";
        } else {
            cout << "Room " << roomNumber << " is already booked.\n";
        }
    }

    void cancelBooking() {
        if (isBooked) {
            cout << "Booking for Room " << roomNumber << " has been canceled.\n";
            isBooked = false;
            customerName = "";
        } else {
            cout << "Room " << roomNumber << " is not booked.\n";
        }
    }

    void displayRoom() {
        cout << "Room " << roomNumber << " - " << (isBooked ? "Booked by " + customerName : "Available") << endl;
    }
};

class Hotel {
private:
    vector<Room> rooms;

public:
    Hotel(int totalRooms) {
        for (int i = 1; i <= totalRooms; i++) {
            rooms.push_back(Room(i));
        }
    }

    void bookRoom(int roomNumber, string name) {
        if (roomNumber > 0 && roomNumber <= rooms.size()) {
            rooms[roomNumber - 1].bookRoom(name);
        } else {
            cout << "Invalid room number!\n";
        }
    }

    void cancelBooking(int roomNumber) {
        if (roomNumber > 0 && roomNumber <= rooms.size()) {
            rooms[roomNumber - 1].cancelBooking();
        } else {
            cout << "Invalid room number!\n";
        }
    }

    void displayRooms() {
        for (Room &r : rooms) {
            r.displayRoom();
        } }};

int main() {
    Hotel hotel(33); // Creating a hotel with 33 rooms
    int choice, roomNumber;
    string name;

    while (true) {
        cout << "\n1. Book Room\n2. Cancel Booking\n3. View Rooms\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter room number: ";
                cin >> roomNumber;
                cout << "Enter customer name: ";
                cin.ignore();
                getline(cin, name);
                hotel.bookRoom(roomNumber, name);
                break;
            case 2:
                cout << "Enter room number: ";
                cin >> roomNumber;
                hotel.cancelBooking(roomNumber);
                break;
            case 3:
                hotel.displayRooms();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;}

