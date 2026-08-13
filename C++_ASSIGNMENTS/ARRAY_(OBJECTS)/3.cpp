//  3. Use another loop to display the details of all students in the array.

#include <iostream>
using namespace std;

class Room
{
    int roomNumber;
    string roomType;
    string guestName;
    string checkInDate;
    string checkOutDate;

    public:
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

        void displayDetails()
        {
            cout << "\nRoom Number: " << roomNumber;
            cout << "\nRoom Type: " << roomType;
            cout << "\nGuest Name: " << guestName;
            cout << "\nCheck-in Date: " << checkInDate;
            cout << "\nCheck-out Date: " << checkOutDate << "\n";
        }

        int getRoomNumber()
        {
            return roomNumber;
        }

        void update()
        {
            cout << "Enter New Guest Name: ";
            cin >> guestName;

            cout << "Enter New Check-out Date: ";
            cin >> checkOutDate;
        }
};

int main()
{
    Room rooms[5];
    int searchRoom = 0;
    int found = 0;

    cout << "Enter details of 5 rooms:\n";

    for (int i = 0; i < 5; i++)
    {
        cout << "\nRoom " << i + 1 << "\n";
        rooms[i].getDetails();
    }

    cout << "\n\n----- All Room Details -----\n";

    for (int i = 0; i < 5; i++)
    {
        rooms[i].displayDetails();
    }

    cout << "\nEnter Room Number to Search: ";
    cin >> searchRoom;

    for (int i = 0; i < 5; i++)
    {
        if (rooms[i].getRoomNumber() == searchRoom)
        {
            cout << "\nRoom Found:\n";
            rooms[i].displayDetails();
            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        cout << "\nRoom Not Found.\n";
    }

    cout << "\nEnter Room Number to Update: ";
    cin >> searchRoom;

    for (int i = 0; i < 5; i++)
    {
        if (rooms[i].getRoomNumber() == searchRoom)
        {
            rooms[i].update();

            cout << "\nUpdated Room Details:\n";
            rooms[i].displayDetails();

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        cout << "\nRoom Not Found.\n";
    }

    return 0;
}