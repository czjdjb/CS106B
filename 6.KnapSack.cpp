// 可以让ai扩大背包容量 增加物品选项
// 计算机常用解决办法就是枚举 遍历
#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;
typedef struct
{
    string name;
    int weight;
    int value;
} item;
bool operator==(const item &a, const item &b)
{
    return a.value == b.value && a.value == b.value;
}
bool operator<(const item &a, const item &b)
{
    if (a.weight != b.weight)
        return a.weight < b.weight;
    return a.value < b.value;
}
int bestBackbag(vector<item> &items, set<vector<item>> &allBag, vector<item> &tempBag, int allWeight, int index, int itemSize)
{
    // 用for循环迭代+递归的办法 在性能上 和yes/not生成子集的办法 在性能上一致 此处用yes/not是为了锻炼能力与街上前面
    // ConstrainSubSets 使得方法连贯 锻炼决策树剪枝的能力 个人还是觉得前者办法更顺手
    // 假如itemSize是因为不能保证即使items全部走了一遍 allWeight可以正好减完 所以需要itemSize保证index不会超过边界
    // 可能不熟悉的缘故 感觉完全逻辑上不如for简单 因为有两个判断条件导致很困难 pop总会跑两次
    int flag = 0;
    cout << tempBag.size() << endl;
    if (allWeight < 0)
    {
        item temp = tempBag.back();
        // itemSize--;
        flag = 1;
        tempBag.pop_back();
        allBag.insert(tempBag);
        tempBag.push_back(temp);
        return flag;
    }
    if (itemSize < 0)
    {
        allBag.insert(tempBag);
        return flag;
    }
    itemSize--;
    item temp = items[index];
    allWeight -= temp.weight;
    tempBag.push_back(temp);
    items.erase(items.begin() + index);
    flag = bestBackbag(items, allBag, tempBag, allWeight, index, itemSize); // yes
    if (flag == 1)
    {
        itemSize--;
    }
    else
        tempBag.pop_back();
    items.insert(items.begin() + index, temp);
    // set保证两个不会重复 因为-1的时候会走两遍 避免重复方案
    flag = bestBackbag(items, allBag, tempBag, allWeight, index + 1, itemSize); // no
    return flag;
}
void knapsack(const vector<item> &items, int capacity, int index,
              vector<item> &current, vector<item> &best, int &bestValue, int currentValue)
{
    if (index == items.size())
    {
        if (currentValue > bestValue)
        {
            bestValue = currentValue;
            best = current;
        }
        return;
    }

    // 不选
    knapsack(items, capacity, index + 1, current, best, bestValue, currentValue);

    // 选（如果放得下）
    if (items[index].weight <= capacity)
    {
        current.push_back(items[index]);
        knapsack(items, capacity - items[index].weight, index + 1,
                 current, best, bestValue, currentValue + items[index].value);
        current.pop_back(); // 回溯
    }
}
int main()
{
    vector<item> items = {
        {"A", 5, 10},
        {"B", 3, 7},
        {"C", 4, 12},
        {"D", 2, 5},
        {"E", 7, 20},
        {"F", 1, 3},
        {"G", 6, 15},
        {"H", 8, 25},
        {"I", 3, 6}};
    int allWeight = 20;
    set<vector<item>> allBag;
    vector<item> tempBag;
    int index = 0;
    int itemSize = items.size();
    // 如果不对这个数据集排序的话 那么可能后面会有达不到的地方
    // 比如对此数据集 跑到E的时候 aW=-1 所以pop 然后选F 此时aW还剩5
    //  GH都不能选 可以选E 但是
    // bestBackbag(items, allBag, tempBag, allWeight, index, itemSize);
    knapsack(items, allBag, tempBag, allWeight, index, itemSize);
    for (vector x : allBag)
    {
        for (item y : x)
        {
            cout << y.name << " ";
        }
        cout << endl;
    }
}