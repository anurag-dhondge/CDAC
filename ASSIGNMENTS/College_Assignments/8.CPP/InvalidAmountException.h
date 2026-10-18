#pragma once

#include <exception>
#include <cstring>
using namespace std;

class InvalidAmountException : public exception
{
private:
    char errMsg[50];

public:

    InvalidAmountException(const char* errMsg)
    {
        strcpy(this->errMsg, errMsg);
    }

    const char* what() const throw()
    {
        return errMsg;
    }
};