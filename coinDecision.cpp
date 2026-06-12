#include <iostream>
#include <cstdio>
#include <string>
#include <queue>
using namespace std;
// H表示head T表示tail
void TransSequence(string allCoin)
{
    cout << allCoin << endl;
}
void EnumerationCoin(int iteration, string allCoin)
{
    if (iteration == 0)
    {
        TransSequence(allCoin);
        return;
    }
    iteration--;
    EnumerationCoin(iteration, allCoin + 'H');
    EnumerationCoin(iteration, allCoin + 'T');
}
int main()
{
    // queue<string> allQueue;
    int iteration = 8;
    string allCoin;
    EnumerationCoin(iteration, allCoin);
    TransSequence(allCoin);
    return 0;
}