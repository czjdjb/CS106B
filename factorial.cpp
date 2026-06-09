#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;

int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    int n = 5;
    int sum;
    // cout << "请输入：";
    // cin >> n;
    sum = factorial(n);
    cout << "sum = " << sum;
    return 0;
}