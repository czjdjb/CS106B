#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;

void moveStack(stack<int> &source, stack<int> &dest)
{
    if (source.empty())
    {
        cout << "empty";
        return;
    }
    int temp = source.top();
    if (!dest.empty() && temp > dest.top())
    {
        cout << "cant move" << endl;
        return;
    }
    source.pop();
    dest.push(temp);
}
void showStack(stack<int> &source, int n)
{
    if (source.empty())
    {
        cout << "-\t";
        return;
    }
    cout << source.top() << "\t";
    source.pop();
}
void showStackAll(stack<int> source, stack<int> aux, stack<int> dest, int n)
{
    for (int i = 0; i < n; i++)
    {
        showStack(source, n);
        showStack(aux, n);
        showStack(dest, n);
        cout << endl;
    }
    cout << endl;
}
void threeMove(stack<int> &source, stack<int> &aux, stack<int> &dest)
{
    int n = 3;
    moveStack(source, dest); // 23 0 1
    showStackAll(source, aux, dest, n);
    // cout << dest.top();
    moveStack(source, aux); // 3 2 1
    showStackAll(source, aux, dest, n);
    moveStack(dest, aux); // 3 12 0
    showStackAll(source, aux, dest, n);
    moveStack(source, dest); // 0 12 3
    showStackAll(source, aux, dest, n);
    moveStack(aux, source); // 1 2 3
    showStackAll(source, aux, dest, n);
    moveStack(aux, dest); // 1 0 23
    showStackAll(source, aux, dest, n);
    moveStack(source, dest); /// 0 0 123
    showStackAll(source, aux, dest, n);
}
void allMove(stack<int> &source, stack<int> &aux, stack<int> &dest, int n, int &count)
{
    if (n == 0)
    {
        return;
    }

    allMove(source, dest, aux, n - 1, count);
    moveStack(source, dest);
    count++;
    allMove(aux, source, dest, n - 1, count);
    showStackAll(source, aux, dest, n); // 打印当前状态
}
int main()
{
    int count = 0;
    int n = 4;
    stack<int> source;
    for (int i = 0; i < n; i++)
    {
        source.push(n - i);
    }
    // cout << source.top();
    stack<int> aux;
    stack<int> dest;
    // showStackAll(source, aux, dest, n);
    // threeMove(source, aux, dest);
    // for (int i = 0; i < 3; i++)
    // {
    //     cout << dest.top() << endl;
    //     dest.pop();
    // }
    allMove(source, aux, dest, n, count);
    cout << "count = " << count << endl;
    return 0;
}