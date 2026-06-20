// class实现4个功能 1 添加一个元素到末尾 2 删除一个并用随机数替代
//  3 看size 4 看是否empty vector<int> 类型
#include <iostream>
#include <vector>
#include "7.RandomBags.h"
using namespace std;
void RandomBags ::addElem(int value)
{
    elems.push_back(value);
}
void RandomBags::RemoveAndRandom(int value)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dsit(1, 6);
    for (int i = 0; i < elems.size(); i++)
    {
        if (elems[i] == value)
        {
            elems[i] = dsit(gen);
        }
    }
}
int RandomBags::VectorSize()
{
    return elems.size();
}
bool RandomBags::isEmpty()
{
    if (VectorSize() != 0)
        return false;
    else
        return true;
}
void RandomBags::PrintRb()
{
    for (int x : elems)
    {
        cout << x << " ";
    }
}
int main()
{
    RandomBags rb;
    cout << rb.isEmpty() << endl;
    rb.addElem(1);
    rb.addElem(2);
    rb.addElem(3);
    rb.addElem(4);
    cout << rb.VectorSize() << endl;
    rb.RemoveAndRandom(2);
    rb.PrintRb();
    return 0;
}