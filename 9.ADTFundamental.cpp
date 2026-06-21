// 记得要加上错误检查 用ai帮忙进行测试 完备性和健壮性很重要
#include <iostream>
#include <string>
#include <set>
#include <string>
#include "9.OurStack.h"
#include "9.OurVector.h"
#include "9.PriorityQueue(heap).h"
using namespace std;
// OurVector的函数
void OurVector::Redfine(int *&a)
{
    int *temp = new int[length];
    for (int i = 0; i < index; i++)
    {
        temp[i] = a[i];
    }
    delete[] a;
    a = temp;
}
int OurVector::size()
{
    return index;
}
void OurVector::printVector()
{
    for (int i = 0; i < index; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void OurVector::add(int value)
{
    if (index >= length)
    {
        length *= 2;
        Redfine(a);
    }
    a[index] = value;
    index++;
}
void OurVector::insert(int index, int value)
{
    index--;
    if (index < 0 || index > this->index)
    {
        cout << "超出边界";
        return;
    }
    if (this->index >= length)
    {
        length *= 2;
        Redfine(a);
    }
    for (int i = this->index; i > index; i--)
    {
        a[i] = a[i - 1];
    }
    a[index] = value;
    this->index++;
}
int OurVector::get(int index)
{
    return a[index];
}
void OurVector::remove(int value)
{
    int j = 0;
    for (int i = 0; i < index; i++)
    {
        if (a[i] != value)
        {
            a[j] = a[i];
            j++;
        }
    }
    index = j;
}
bool OurVector::isEmpty()
{
    if (index == 0)
        return true;
    else
        return false;
}

// Heap的函数
Heap ::Heap(int length)
{
    this->length = length;
    a = new int[length];
}
Heap::~Heap()
{
    delete[] a;
}
void Heap::CountIndex(int index)
{
    Pindex = (index - 1) / 2;
    Lindex = 2 * index + 1;
    Rindex = 2 * index + 2;
}
void Heap::reDefine(int *&a)
{
    int *temp = new int[length];
    for (int i = 0; i < backIndex; i++)
    {
        temp[i] = a[i];
    }
    delete[] a;
    a = temp;
}
void Heap::enqueue(int value)
{
    if (backIndex == length)
    {
        length *= 2;
        reDefine(a);
    }
    a[backIndex] = value;
    int tempIndex = backIndex;
    while (1)
    {
        if (tempIndex == 0)
            break;
        CountIndex(tempIndex);
        if (a[Pindex] > value)
        {
            int temp = a[Pindex];
            a[Pindex] = a[tempIndex];
            a[tempIndex] = temp;
            tempIndex = Pindex;
        }
        else
            break;
    }
    backIndex++;
}
int Heap::dequeue()
{
    int indexN = 0;
    int temp;
    int flag = 0;
    int final = a[indexN];
    a[indexN] = a[backIndex - 1];
    backIndex--;
    while (1)
    {
        // 我的写法没有判断 当只有Lindex或者只有Rindex的时候会怎样 这样会导致越界
        //  if (indexN == backIndex || flag == 1)
        //      break;
        //  CountIndex(indexN);
        //  if (a[indexN] < a[Lindex] && a[indexN] < a[Rindex])
        //  {
        //      flag = 1;
        //  }
        //  if (a[Lindex] < a[Rindex])
        //  {
        //      temp = a[Lindex];
        //      a[Lindex] = a[indexN];
        //      a[indexN] = temp;
        //      indexN = Lindex;
        //  }
        //  else
        //  {
        //      temp = a[Rindex];
        //      a[Rindex] = a[indexN];
        //      a[indexN] = temp;
        //      indexN = Rindex;
        //  }

        CountIndex(indexN);
        int smallest = indexN;
        if (Lindex < backIndex && a[Lindex] < a[smallest])
            smallest = Lindex;
        if (Rindex < backIndex && a[Rindex] < a[smallest])
            smallest = Rindex;
        if (smallest == indexN)
            break;
        swap(a[indexN], a[smallest]);
        indexN = smallest;
    }
    return final;
}
void Heap::PrintHeap()
{
    for (int i = 0; i < backIndex; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void Heap ::peek()
{
    cout << a[0];
}
int Heap::size()
{
    return backIndex;
}
bool Heap::isempty()
{
    if (backIndex == 0)
        return true;
    else
        return false;
}
void Heap::clear()
{
    int *tempHeap = new int[length];
    delete[] a;
    a = tempHeap;
    backIndex = 0;
}
int main()
{
    // //Vecotr的测试
    // OurVector a(10);
    // for (int i = 0; i < 5; i++)
    // {
    //     a.add(i);
    // }
    // a.printVector();
    // a.insert(2, 2);
    // a.printVector();
    // a.remove(4);
    // a.printVector();

    // Heap的测试
    // Heap a(10);
    // cout << a.isempty() << endl;
    // //具体图见 obsidian ai infra cs106b
    // a.enqueue(4);
    // a.enqueue(6);
    // a.enqueue(8);
    // a.enqueue(7);
    // a.enqueue(9);
    // a.PrintHeap();
    // int i = a.dequeue();
    // cout << i << endl;
    // i = a.dequeue();
    // cout << i << endl;
    // i = a.dequeue();
    // cout << i << endl;
    // i = a.dequeue();
    // cout << i << endl;
    return 0;
}