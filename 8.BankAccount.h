#pragma once
#include <string>
using namespace std;
class bankAccount
{
public:
    bankAccount(string a, int b) : name(a), money(b) {}
    void PrintAccount();
    void PrintAccountName();
    void PrintAccountMoney();
    void SaveMoney(int value);
    void ChargeMoney(int value);
    void TransferMoney(bankAccount &man, int value);

private:
    string name;
    int money;
};