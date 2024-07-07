#ifndef showExpenses_H
#define showExpenses_H
#include <iostream>
#include <string>
#include "../model/logBook.h"
#include "addExpenses.h"

using namespace std;

class showExpenses
{
public:
    void showAllExp(logBook *logbook)
    {
        logbook->traverseDebtorCreditorMap();
        return;
    }
    void showSpecificExpense(logBook *logbook, string userName)
    {
        logbook->traverseforSpecificUser(userName);
        return;
    }
};
#endif