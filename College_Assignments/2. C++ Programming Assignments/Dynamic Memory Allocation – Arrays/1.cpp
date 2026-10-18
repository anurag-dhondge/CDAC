/*
    1.  Write a menu-driven C++ program to dynamically allocate an integer array of N elements and perform
        the following operations using user-defined functions:
        1. Accept and display the array elements.
        2. Find and display the largest and smallest elements.
        3. Calculate and display the sum and average of the array elements.
        4. Count and display the number of even and odd elements.
        5. Search for a given element using linear search.
        6. Exit the program.
*/

#include <iostream>
using namespace std;

// 1.Accept array elements
void Accept(int *arr, int n)
{
    cout << "Enter " << n << " elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

// 1.Display array elements
void Display(int *arr, int n)
{
    cout << "Array elements: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}

// 2.Find largest and smallest elements
void Largest_Smallest(int *arr, int n)
{
    int largest = arr[0];
    int smallest = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] > largest)
            largest = arr[i];

        if (arr[i] < smallest)
            smallest = arr[i];
    }

    cout << "Largest = " << largest << endl;
    cout << "Smallest = " << smallest << endl;
}

// 3.Calculate sum and average
void Sum_Average(int *arr, int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    float average = (float)sum / n;

    cout << "Sum = " << sum << endl;
    cout << "Average = " << average << endl;
}

// 4.Count even and odd elements
void Even_Odd(int *arr, int n)
{
    int even = 0;
    int odd = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    cout << "Even elements = " << even << endl;
    cout << "Odd elements = " << odd << endl;
}

// 5.Linear search
void Linear_Search(int *arr, int n)
{
    int key;
    bool found = false;

    cout << "Enter element to search: ";
    cin >> key;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout << "Element found at position " << i + 1 << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Element not found." << endl;
}

int main()
{
    int n, choice;

    cout << "Enter number of elements: ";
    cin >> n;

    // Dynamically allocate array
    int *arr = new int[n];

    do
    {
        cout << "\n----- MENU -----\n";
        cout << "1. Accept and Display Array\n";
        cout << "2. Largest and Smallest\n";
        cout << "3. Sum and Average\n";
        cout << "4. Count Even and Odd\n";
        cout << "5. Linear Search\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Accept(arr, n);
            Display(arr, n);
            break;

        case 2:
            Largest_Smallest(arr, n);
            break;

        case 3:
            Sum_Average(arr, n);
            break;

        case 4:
            Even_Odd(arr, n);
            break;

        case 5:
            Linear_Search(arr, n);
            break;

        case 6:
            cout << "Exiting program..."; //6.Exit
            break;

        default:
            cout << "Invalid choice!";
        }

    } while (choice != 6);

    // Release dynamically allocated memory
    delete[] arr;

    return 0;
}