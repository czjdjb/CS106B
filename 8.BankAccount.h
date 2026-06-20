#pragma once
#include <string>
using namespace std;
class bankAccount
{
public:
    bankAccount(string a, int b) : name(a), money(b) {} // 用下面这个更好 可以避免原值copy
    // BankAccount(const std::string& name, double initialBalance);
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