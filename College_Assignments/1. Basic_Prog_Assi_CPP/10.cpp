/*
    10. Accept a character and use switch-case to
        determine whether it is a vowel.
        If it is not a vowel, display that it is a consonant.
*/

#include <iostream>
using namespace std;

void Check_Vowel(char ch)
{
    char wish;
    do
    {
        switch(ch)
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
            case 'A':
            case 'E':
            case 'I':
            case 'O':
            case 'U':
                cout << "The character " << ch << " is vowel";
                break;

            default:
                cout << "The character " << ch << " is consonant";
                break;
        }

        cout << "\nDo you wish to continue? (Y/N): ";
        cin >> wish;

    } while(wish == 'y' || wish == 'Y');
}

int main()
{
    char ch; 
    cout << "Enter a character: "; 
    cin >> ch; 
    Check_Vowel(ch);

    return 0;
}