#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;
void PeopleGroup(vector<string> &allPeople, set<set<string>> &subSets, set<string> &tempSets, int iteration)
// 与v_ai比 复杂度高 用索引只有O（1） 像我用erase insert是O（n)
{
    if (iteration == 0)
    {
        subSets.insert(tempSets);
        return;
    }
    // cout << allPeople.size() << endl;
    iteration--;
    string elem = allPeople[iteration];
    allPeople.erase(allPeople.begin() + iteration); // 注意索引问题 之前用push——back和pop——back 导致索引紊乱 插入的是
                                                    // allPeople[iteration] 但是push——back的是最后一位 出现大量重复 无法写入set
    tempSets.insert(elem);
    PeopleGroup(allPeople, subSets, tempSets, iteration); // yes
    allPeople.insert(allPeople.begin() + iteration, elem);
    tempSets.erase(elem);
    PeopleGroup(allPeople, subSets, tempSets, iteration); // no
}
void PeopleGroupV_ai(vector<string> &allPeople, set<set<string>> &subSets,
                     set<string> &tempSets, int index)
{
    if (index == allPeople.size())
    {
        subSets.insert(tempSets);
        return;
    }

    // 不选
    PeopleGroup(allPeople, subSets, tempSets, index + 1);

    // 选
    tempSets.insert(allPeople[index]);
    PeopleGroup(allPeople, subSets, tempSets, index + 1);
    tempSets.erase(allPeople[index]); // 回溯
}
int main()
{
    vector<string> allPeople = {"Alice", "Bob", "Charlie",
                                "Diana", "Eve", "Frank", "Grace", "Henry", "Ivy"};
    set<set<string>> subSets;
    set<string> tempSets;
    int iteration = allPeople.size();
    PeopleGroup(allPeople, subSets, tempSets, iteration);
    // PeopleGroupV_ai(allPeople, subSets, tempSets, iteration); //ai有点问题还需调试 但是思路一样
    int count = 0;
    for (set<string> x : subSets)
    {
        for (string y : x)
        {
            // cout << y << " ";
        }
        // cout << endl;
        count++;
    }
    cout << count;
}