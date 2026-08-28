/*
    2.  Write a menu-driven C++ program to dynamically allocate memory for the prices of N products in a
        store and perform the following operations using user-defined functions:
        1. Accept and display the product prices.
        2. Find and display the highest and lowest-priced products.
        3. Calculate and display the total inventory value and average product price.
        4. Count the number of products whose price is above and below the average price.
        5. Search for a particular product price using linear search.
        6. Apply a given discount percentage to all product prices and display the updated prices.
        7. Exit the program
*/

#include <iostream>
using namespace std;

// 1.Function to accept prices
void Accept_Prices(float *price, int n)
{
    cout << "Enter prices of " << n << " products:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Product " << i + 1 << ": ";
        cin >> price[i];
    }
}

// 1.Function to display prices
void Display_Prices(float *price, int n)
{
    cout << "\nProduct Prices:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Product " << i + 1 << ": " << price[i] << endl;
    }
}

// 2.Function to find highest and lowest price
void Find_HighLow(float *price, int n)
{
    float highest = price[0];
    float lowest = price[0];

    for (int i = 1; i < n; i++)
    {
        if (price[i] > highest)
            highest = price[i];

        if (price[i] < lowest)
            lowest = price[i];
    }

    cout << "\nHighest Price: " << highest << endl;
    cout << "Lowest Price: " << lowest << endl;
}

// 3.Function to calculate total and average
float Calculate_Average(float *price, int n)
{
    float total = 0;

    for (int i = 0; i < n; i++)
    {
        total += price[i];
    }

    float average = total / n;

    cout << "\nTotal Inventory Value: " << total << endl;
    cout << "Average Product Price: " << average << endl;

    return average;
}

// 4.Function to count prices above and below average
void Count_AboveBelow(float *price, int n, float average)
{
    int above = 0;
    int below = 0;

    for (int i = 0; i < n; i++)
    {
        if (price[i] > average)
            above++;
        else if (price[i] < average)
            below++;
    }

    cout << "\nProducts above average: " << above << endl;
    cout << "Products below average: " << below << endl;
}

// 5.Function for linear search
void Search_Price(float *price, int n)
{
    float search;
    bool found = false;

    cout << "\nEnter price to search: ";
    cin >> search;

    for (int i = 0; i < n; i++)
    {
        if (price[i] == search)
        {
            cout << "Price found at Product " << i + 1 << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Price not found." << endl;
}

// 6.Function to apply discount
void Apply_Discount(float *price, int n)
{
    float discount;

    cout << "\nEnter discount percentage: ";
    cin >> discount;

    for (int i = 0; i < n; i++)
    {
        price[i] = price[i] - (price[i] * discount / 100);
    }

    cout << "\nPrices after discount:\n";
    Display_Prices(price, n);
}

int main()
{
    int n, choice;

    cout << "Enter number of products: ";
    cin >> n;

    // Dynamic memory allocation
    float *price = new float[n];

    Accept_Prices(price, n);

    do
    {
        cout << "\n*****MENU*****\n";
        cout << "1. Display Product Prices\n";
        cout << "2. Find Highest and Lowest Price\n";
        cout << "3. Calculate Total and Average\n";
        cout << "4. Count Above and Below Average\n";
        cout << "5. Search Product Price\n";
        cout << "6. Apply Discount\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                Display_Prices(price, n);
                break;

            case 2:
                Find_HighLow(price, n);
                break;

            case 3:
                Calculate_Average(price, n);
                break;

            case 4:
            {
                float average = Calculate_Average(price, n);
                Count_AboveBelow(price, n, average);
                break;
            }

            case 5:
                Search_Price(price, n);
                break;

            case 6:
                Accept_Prices(price, n);
                break;

            case 7:
                cout << "\nExiting program...\n"; // 7. Exit
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 7);

    // Free dynamically allocated memory
    delete[] price;

    return 0;
}