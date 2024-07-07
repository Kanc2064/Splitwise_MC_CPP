#ifndef invalidInputSumException_H
#define invalidInputSumException_H
#include <iostream>

class invalidInputSumException
{
    string exceptionMessage;

public:
    invalidInputSumException(string exceptionMessage)
    {
        this->exceptionMessage = exceptionMessage;
    }
    void getException()
    {
        cout << this->exceptionMessage << endl;
    }
};
#endif