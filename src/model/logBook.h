#ifndef logBook_H
#define logBook_H
#include <iostream>
#include <stdbool.h>
#include <map>
#include <utility>

using namespace std;

class logBook
{

private:
    map<pair<string, string>, int> CreditordebtorMap;

public:
    void traverseDebtorCreditorMap()
    {
        if (CreditordebtorMap.size() == 0)
        {
            cout << "No Balance" << endl;
            return;
        }
        for (auto it : CreditordebtorMap)
        {
            string creditor;
            string debtor;
            int owedAmt;
            if (it.second > 0)
            {
                creditor = it.first.first;
                debtor = it.first.second;
                owedAmt = it.second;
                cout << debtor << " owes " << owedAmt << " to " << creditor << endl;
            }
            else if (it.second < 0)
            {
                debtor = it.first.first;
                creditor = it.first.second;
                owedAmt = it.second * (-1);
                cout << debtor << " owes " << owedAmt << " to " << creditor << endl;
            }
        }
    }

    void traverseforSpecificUser(string userName)
    {
        if (CreditordebtorMap.size() == 0)
        {
            cout << "No Balance" << endl;
            return;
        }
        for (auto it : CreditordebtorMap)
        {
            string creditor;
            string debtor;
            int owedAmt;
            if (it.second > 0)
            {
                creditor = it.first.first;
                debtor = it.first.second;
                owedAmt = it.second;
                if (userName == creditor || userName == debtor)
                {
                    cout << debtor << " owes " << owedAmt << " to " << creditor << endl;
                }
            }
            else if (it.second < 0)
            {
                debtor = it.first.first;
                creditor = it.first.second;
                owedAmt = it.second;
                if (userName == creditor || userName == debtor)
                {
                    cout << debtor << " owes " << owedAmt << " to " << creditor << endl;
                }
            }
        }
    }

    void addExp(string creditor, string debtor, int amt)
    {
        if (CreditordebtorMap.find({creditor, debtor}) != CreditordebtorMap.end())
        {
            CreditordebtorMap[{creditor, debtor}] += amt;
        }
        else if (CreditordebtorMap.find({debtor, creditor}) != CreditordebtorMap.end())
        {
            CreditordebtorMap[{debtor, creditor}] -= amt;
        }
        else
        {
            CreditordebtorMap[{creditor, debtor}] = amt;
        }
    }
};
#endif