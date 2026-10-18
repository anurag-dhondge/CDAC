#pragma once

#include <exception>
#include <cstring>
using namespace std;

class InsufficientBalanceException : public exception
{
private:
    char errMsg[50];

public:

    InsufficientBalanceException(const char* errMsg)
    {
        strcpy(this->errMsg, errMsg);
    }

    const char* what() const throw()
    {
        return errMsg;
    }
};