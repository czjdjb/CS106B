// 用tree来生成合适的编码 path代表具体编码 同时用这个树去解码
// 字符信息只存储在叶子节点 按照出现频率 排序
// 编写霍夫曼编码 最佳二叉树 binary tree 左0右1
#include <iostream>
#include <string>
#include <vector>
#include "9.PriorityQueue(heap).h"
using namespace std;
typedef struct
{
    char word;
    int num;
} hello;
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
void PrintHello(vector<hello> allWord)
{
    for (hello x : allWord)
    {
        cout << x.word << " ";
        cout << x.num << endl;
    }
}
void TestWord(vector<hello> &allWord, const string &text)
{
    int flag;
    for (char x : text)
    {
        flag = 0;
        if (x > 64 && x < 91)
            x += 32;
        for (int i = 0; i < allWord.size(); i++)
        {
            if (x == allWord[i].word)
            {
                allWord[i].num++;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            allWord.push_back({x, 1});
        }
        // cout << allWord.size() << endl;
    }
}
int main(void)
{
    string text =
        "The quick brown fox jumps over the lazy dog. "
        "A mad boxer shot a quick, gloved jab to the jaw of his dizzy opponent. "
        "Sixty zippers were quickly picked from the woven jute bag. "
        "The job requires extra pluck and zeal from every young wage earner. "
        "Freight to me sixty dozen quart jars and twelve black pans. "
        "We have just quoted on nine dozen boxes of gray lamp wicks. "
        "The public was amazed to view the quickness and dexterity of the juggler. "
        "We promptly judged antique ivory buckles for the next prize. "
        "Heavy boxes perform quick waltzes and jigs. "
        "Jaded zombies acted quaintly but kept driving their oxen forward.";
    vector<hello> allWord;
    Heap allHeap(40);
    TestWord(allWord, text);
    // PrintHello(allWord);
}