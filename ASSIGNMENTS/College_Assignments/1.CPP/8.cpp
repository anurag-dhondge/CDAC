/*
    8. Create a menu-driven calculator using switch-case.
       The user should select addition, subtraction, multiplication,
       division, or modulus and enter two numbers.
*/

#include <iostream>
using namespace std;

void Calculator(int choice, int a, int b)
{
    char wish;

    do
    {
        switch(choice)
        {
            case 1:
                cout << "Addition = " << a + b;
                break;

            case 2:
                cout << "Subtraction = " << a - b;
                break;

            case 3:
                cout << "Multiplication = " << a * b;
                break;

            case 4:
                if(b != 0)
                {
                    cout << "Division = " << (float)a / b;
                }
                else
                {
                    cout << "Cannot divide by zero";
                }
                break;

            case 5:
                if(b != 0)
                {
                    cout << "Modulus = " << a % b;
                }
                else
                {
                    cout << "Cannot divide by zero";
                }
                break;

            default:
                cout << "Invalid choice";
                break;
        }

        cout << "\nDo you wish to continue? (Y/N): ";
        cin >> wish;

        if(wish == 'y' || wish == 'Y')
        {
            cout << "\n1. Addition\n";
            cout << "2. Subtraction\n";
            cout << "3. Multiplication\n";
            cout << "4. Division\n";
            cout << "5. Modulus\n";

            cout << "Enter choice: ";
            cin >> choice;

            cout << "Enter two numbers: ";
            cin >> a >> b;
        }

    } while(wish == 'y' || wish == 'Y');
}

int main()
{
    int choice, a, b;

    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "5. Modulus\n";

    cout << "Enter choice: ";
    cin >> choice;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    Calculator(choice, a, b);

    return 0;
}