#ifndef addExpenses_H
#define addExpenses_H
#include <iostream>
#include <string>
#include <vector>
#include "../model/logBook.h"

using namespace std;

class addExpenses
{
public:
    void addExpenses_Equal(string payee, vector<string> oweeList, int paidAmt, logBook *logbook, int numOfOwee)
    {
        int amt = paidAmt / numOfOwee;
        int n = oweeList.size();
        for (int i = 0; i < numOfOwee; i++)
        {
            string owee = oweeList[i];
            if (owee != payee)
            {
                logbook->addExp(payee, owee, amt);
            }
        }
        return;
    }
    void addExpenses_Exact(string payee, vector<string> oweeList, vector<int> owedAmtList, int paidAmt, logBook *logbook, int numOfOwee)
    {
        for (int i = 0; i < numOfOwee; i++)
        {
            string owee = oweeList[i];
            if (owee != payee)
            {
                logbook->addExp(payee, owee, owedAmtList[i]);
            }
        }
        return;
    }
    void addExpenses_Percent(string payee, vector<string> oweeList, vector<int> owedAmtList, int paidAmt, logBook *logbook, int numOfOwee)
    {
        for (int i = 0; i < numOfOwee; i++)
        {
            string owee = oweeList[i];
            if (owee != payee)
            {
                logbook->addExp(payee, owee, owedAmtList[i]);
            }
        }
        return;
    }
};
#endif