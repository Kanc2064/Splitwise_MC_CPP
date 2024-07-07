#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "model/logBook.h"
#include "services/showExpenses.h"
#include "services/addExpenses.h"
#include "customException/invalidInputSumException.h"

using namespace std;

int main()
{
    typedef pair<int, int> p;
    priority_queue<p> minh;
    minh.push({5, 6});
    minh.push({6, 7});
    cout << minh.top().first;
    logBook *logbook = new logBook();
    showExpenses *showexpense = new showExpenses();
    addExpenses *addexpense = new addExpenses();

    string activityType;

    string payee;
    int paidAmt;
    int numOfOwee;
    string owee;

    string splitType;
    string username;

    while (true)
    {
        try
        {
            cout << "what activity you want to perform? e.g.: SHOW/EXPENSE" << endl;
            cin >> activityType;
            if (activityType == "SHOW")
            {
                string choice;
                cout << "Do you want to see details of specific user? yes or no" << endl;
                cin >> choice;
                cout << endl;
                if (choice == "yes")
                {
                    cin >> username;
                    showexpense->showSpecificExpense(logbook, username);
                }
                else if (choice == "no")
                {
                    showexpense->showAllExp(logbook);
                }
            }
            else if (activityType == "EXPENSE")
            {
                cout << "Enter payee Name" << endl;
                cin >> payee;
                cout << endl;
                cout << "Enter paid Amount" << endl;
                cin >> paidAmt;
                cout << endl;
                cout << "Enter Number Of Owee" << endl;
                cin >> numOfOwee;
                cout << endl;
                cout << "enter all owee names" << endl;
                vector<string> oweeList;
                for (int i = 0; i < numOfOwee; i++)
                {
                    cin >> owee;
                    oweeList.push_back(owee);
                }
                cout << "How Do you want to split the balance? e.g.: EQUAL,EXACT or PERCENT?" << endl;
                cin >> splitType;
                if (splitType == "EQUAL")
                {
                    addexpense->addExpenses_Equal(payee, oweeList, paidAmt, logbook, numOfOwee);
                }
                else if (splitType == "EXACT")
                {
                    int expensesTotalSum = 0;
                    vector<int> owedAmtList;
                    int owedAmt;
                    cout << "enter individual expenses" << endl;
                    for (int i = 0; i < numOfOwee; i++)
                    {
                        cin >> owedAmt;
                        expensesTotalSum += owedAmt;
                        owedAmtList.push_back(owedAmt);
                    }
                    if (expensesTotalSum == paidAmt)
                    {
                        addexpense->addExpenses_Exact(payee, oweeList, owedAmtList, paidAmt, logbook, numOfOwee);
                    }
                    else
                    {
                        invalidInputSumException *exc1 = new invalidInputSumException("exact exception");
                        throw exc1;
                        // cout<< "Total expenses not equal to paid amount" << endl;
                    }
                }
                else if (splitType == "PERCENT")
                {
                    int percentagesTotalSum = 0;
                    vector<int> owedAmtList;
                    int owedAmtPercent;
                    cout << "enter individual percentages" << endl;
                    for (int i = 0; i < numOfOwee; i++)
                    {
                        cin >> owedAmtPercent;
                        percentagesTotalSum += owedAmtPercent;
                        owedAmtList.push_back((paidAmt * owedAmtPercent) / 100);
                    }
                    if (percentagesTotalSum == 100)
                    {
                        addexpense->addExpenses_Percent(payee, oweeList, owedAmtList, paidAmt, logbook, numOfOwee);
                    }
                    else
                    {
                        invalidInputSumException *exc2 = new invalidInputSumException("percent exception");
                        throw exc2;
                    }
                }
            }
        }
        catch (invalidInputSumException *exc)
        {
            exc->getException();
        }
    }

    return 0;
}