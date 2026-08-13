/*
    4. Create a C++ program that demonstrates the use of arrays of objects.
    The program should simulate a simple hotel reservation system.

    a. Create a class Room with the following attributes:
    - roomNumber (integer), roomType (string), guestName (string), checkInDate (string),
      checkOutDate (string)
    b. Implement the following member functions in the Room class:
    - getDetails(): Asks the user to input the room's details(room number, room type, guest name,
      check-in date, and check-out date)
    - displayDetails(): Displays the room's details.
    c. Create an array of Room objects with a size of 5.
    d. Use a loop to ask the user to input the details of 5 rooms and store them in the array.
    e. Use another loop to display the details of all rooms in the array.
    f. Implement a function to search for a room by room number and display its details if found.
    g. Implement a function to update the guest name and check-out date of a room.
*/

#include <iostream>
using namespace std;

// a. Create Room class
class Room
{
    private:
        int roomNumber = 0;
        string roomType;
        string guestName;
        string checkInDate;
        string checkOutDate;

    public:

        // b. Function to accept details
        void getDetails()
        {
            cout << "Enter Room Number: ";
            cin >> roomNumber;

            cout << "Enter Room Type: ";
            cin >> roomType;

            cout << "Enter Guest Name: ";
            cin >> guestName;

            cout << "Enter Check-in Date: ";
            cin >> checkInDate;

            cout << "Enter Check-out Date: ";
            cin >> checkOutDate;
        }

        // b. Function to display details
        void displayDetails()
        {
            cout << "\nRoom Number: " << roomNumber;
            cout << "\nRoom Type: " << roomType;
            cout << "\nGuest Name: " << guestName;
            cout << "\nCheck-in Date: " << checkInDate;
            cout << "\nCheck-out Date: " << checkOutDate;
            cout << endl;
        }

        int getRoomNumber()
        {
            return roomNumber;
        }

        // g. Function to update details
        void updateDetails()
        {
            cout << "Enter New Guest Name: ";
            cin >> guestName;

            cout << "Enter New Check-out Date: ";
            cin >> checkOutDate;
        }
};

// d. Function to accept details of 5 rooms
void acceptRooms(Room rooms[])
{
    for (int i = 0; i < 5; i++)
    {
        cout << "\nEnter details of Room " << i + 1 << ":\n";
        rooms[i].getDetails();
    }
}

// e. Function to display details of all rooms
void displayRooms(Room rooms[])
{
    for (int i = 0; i < 5; i++)
    {
        cout << "\nRoom " << i + 1 << " Details:";
        rooms[i].displayDetails();
    }
}

// f. Function to search for a room
void searchRoom(Room rooms[])
{
    int roomNumber;
    bool found = false;

    cout << "\nEnter Room Number to Search: ";
    cin >> roomNumber;

    for (int i = 0; i < 5; i++)
    {
        if (rooms[i].getRoomNumber() == roomNumber)
        {
            cout << "\nRoom Found!";
            rooms[i].displayDetails();

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nRoom Not Found!";
    }
}

// g. Function to update a room
void updateRoom(Room rooms[])
{
    int roomNumber;
    bool found = false;

    cout << "\nEnter Room Number to Update: ";
    cin >> roomNumber;

    for (int i = 0; i < 5; i++)
    {
        if (rooms[i].getRoomNumber() == roomNumber)
        {
            rooms[i].updateDetails();

            cout << "\nRoom Updated Successfully!";
            cout << "\nUpdated Room Details:";

            rooms[i].displayDetails();

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nRoom Not Found!";
    }
}

int main()
{
    // c. Create an array of 5 Room objects
    Room rooms[5];

    // d. Accept details of 5 rooms
    cout << "===== ENTER ROOM DETAILS =====\n";
    acceptRooms(rooms);

    // e. Display details of all rooms
    cout << "\n===== ALL ROOM DETAILS =====\n";
    displayRooms(rooms);

    // f. Search for a room
    cout << "\n===== SEARCH ROOM =====\n";
    searchRoom(rooms);

    // g. Update a room
    cout << "\n===== UPDATE ROOM =====\n";
    updateRoom(rooms);

    return 0;
}