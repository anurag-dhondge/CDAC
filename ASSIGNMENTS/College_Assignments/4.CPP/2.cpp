#include <iostream>
#include "Library.h"

using namespace std;

int main() {
    // 1. Create object using Parameterized Constructor
    LibraryMember member1(101, "Alex", 3);
    member1.accept();
    member1.display();

    // 2. Create another object using Copy Constructor
    LibraryMember member2 = member1;

    cout << "\n--- Displaying Copied Member ---";
    member2.display();

    return 0; // Destructors trigger automatically when objects go out of scope
}