// 让ai生成需求 去实现
/*
1. 构造器：传入姓名和初始余额
2. 存款
3. 取款（余额不足返回 false）
4. 查询余额
5. 查询姓名
6. 转账到另一个账户
7. 打印账户信息
*/
#include <iostream>
#include <string>
#include <stdexcept> // error的库
#include "8.BankAccount.h"
using namespace std;
void bankAccount::PrintAccount()
{
    cout << "Name = " << name << endl;
    cout << "Money = " << money << endl;
}
void bankAccount::PrintAccountName()
{
    cout << "Name = " << name << endl;
}
void bankAccount::PrintAccountMoney()
{
    cout << "Money = " << money << endl;
}
void bankAccount::SaveMoney(int value)
{
    money += value;
    PrintAccountMoney();
}
void bankAccount::ChargeMoney(int value)
{
    if (money < value)
        throw "less money"; // #include <stdexcept> 这个库
    money -= value;
    PrintAccountMoney();
}
void bankAccount::TransferMoney(bankAccount &man, int value)
{
    money -= value;
    man.money += value;
    PrintAccount();
    man.PrintAccount();
}
int main()
{
    bankAccount a("man1", 1000);
    bankAccount b("man2", 1000);
    a.SaveMoney(100);
    a.ChargeMoney(100);
    a.TransferMoney(b, 500);
    b.PrintAccount();
    return 0;
}