#pragma once
#include <iostream>
#include <string>

using namespace std;

class LibraryMember {
private:
    int id;
    string name;
    int noOfBooks;
    int* barr; // Dynamic array to store book IDs

public:
    // Default Constructor
    LibraryMember() {
        id = 0;
        name = "NA";
        noOfBooks = 0;
        barr = nullptr; // Prevents garbage memory access
    }

    // Parameterized Constructor
    LibraryMember(int id, string name, int noOfBooks) {
        this->id = id;
        this->name = name;
        this->noOfBooks = noOfBooks;

        if (this->noOfBooks > 0) {
            barr = new int[this->noOfBooks];
            for (int i = 0; i < this->noOfBooks; i++) {
                barr[i] = 0;
            }
        }
        else {
            barr = nullptr;
        }
    }

    // Copy Constructor (Deep Copy)
    LibraryMember(const LibraryMember& copyObj) {
        this->id = copyObj.id;
        this->name = copyObj.name;
        this->noOfBooks = copyObj.noOfBooks;

        if (this->noOfBooks > 0 && copyObj.barr != nullptr) {
            this->barr = new int[this->noOfBooks];
            for (int i = 0; i < this->noOfBooks; i++) {
                this->barr[i] = copyObj.barr[i];
            }
        }
        else {
            this->barr = nullptr;
        }
    }

    // Accept book IDs from user
    void accept() {
        if (noOfBooks > 0 && barr != nullptr) {
            cout << "Enter " << noOfBooks << " Book IDs:" << endl;
            for (int i = 0; i < noOfBooks; i++) {
                cin >> barr[i];
            }
        }
    }

    // Display member details and book list
    void display() const {
        cout << "\nMember ID: " << id
            << " | Name: " << name
            << " | Books Issued: " << noOfBooks << endl;

        if (noOfBooks > 0 && barr != nullptr) {
            cout << "Book IDs: ";
            for (int i = 0; i < noOfBooks; i++) {
                cout << barr[i] << " ";
            }
            cout << endl;
        }
    }

    // Destructor
    ~LibraryMember() {
        if (barr != nullptr) {
            delete[] barr;
            barr = nullptr;
        }
        cout << "Member object (ID: " << id << ") removed from memory." << endl;
    }
};