// 总的集合大小为9 只需要子集合为5的情况
// 用yes/no 的方法会更好 因为for是排列 而 yes/no 是组合 虽然有set防止重复 但是当set过大的时候 会速度慢很多
#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;
void SubSetsMake(set<set<string>> &allSet, int iteration, vector<string> &allPeople, set<string> tempSet)
{
    if (iteration < 0)
    {
        allSet.insert(tempSet);
        return;
    }
    iteration--;
    for (int i = 0; i < allPeople.size(); i++)
    {
        string tempS = allPeople[i];
        tempSet.insert(tempS);
        allPeople.erase(allPeople.begin() + i);
        SubSetsMake(allSet, iteration, allPeople, tempSet);
        tempSet.erase(tempS);
        allPeople.insert(allPeople.begin() + i, tempS);
    }
}
int main()
{
    vector<string> allPeople = {"Alice", "Bob", "Charlie",
                                "Diana", "Eve", "Frank", "Grace", "Henry", "Ivy"};
    set<set<string>> allSet;
    set<string> tempSet;
    int iteration = 4;
    SubSetsMake(allSet, iteration, allPeople, tempSet);
    for (set x : allSet)
    {
        for (string y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    return 0;
}
