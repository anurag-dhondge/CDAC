/*
    11. Create a menu using switch-case to calculate the
        area of a circle, rectangle, square, or triangle
        based on the user's choice.
*/

#include <iostream>
using namespace std;

void Area(int choice)
{
    float r, l, b, s, h;
    char wish;

    do
    {
        switch(choice)
        {
            case 1:
                cout << "Enter radius: ";
                cin >> r;
                cout << "Area = " << 3.14 * r * r;
                break;

            case 2:
                cout << "Enter length and breadth: ";
                cin >> l >> b;
                cout << "Area = " << l * b;
                break;

            case 3:
                cout << "Enter side: ";
                cin >> s;
                cout << "Area = " << s * s;
                break;

            case 4:
                cout << "Enter base and height: ";
                cin >> b >> h;
                cout << "Area = " << 0.5 * b * h;
                break;

            default:
                cout << "Invalid choice";
                break;
        }

        cout << "\nDo you wish to continue? (Y/N): ";
        cin >> wish;

        if(wish == 'y' || wish == 'Y')
        {
            cout << "\n1. Circle\n";
            cout << "2. Rectangle\n";
            cout << "3. Square\n";
            cout << "4. Triangle\n";

            cout << "Enter choice: ";
            cin >> choice;
        }

    } while(wish == 'y' || wish == 'Y');
}

int main()
{
    int choice;

    cout << "1. Circle\n";
    cout << "2. Rectangle\n";
    cout << "3. Square\n";
    cout << "4. Triangle\n";

    cout << "Enter choice: ";
    cin >> choice;

    Area(choice);

    return 0;
}