/*
    1.  Write a program to accept an integer and 
        determine whether it is positive, negative, or zero 
        using if-else. 
*/

#include <iostream>
using namespace std;

void Check_Number(float no)
{
    if(no > 0)
    {
        cout << "The integer is positive" << endl;
    }

    else if(no < 0)
    {
        cout << "->The integer is negative" << endl;
    }

    else if(no = 0)
    {
        cout << "The integer is zero" << endl;
    }

    else
    {
        cout << "Inalid Input";
    }

}

int main()
{
    float num = 0.0f , ret = 0.0f;

    cout << "Enter a integer : ";
    cin >> num;

    Check_Number(num);

    return 0;
}
