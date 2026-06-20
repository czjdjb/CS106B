// 功能 1 enqueue 2 dequeue 3 peek（看最先出队的元素） 4 size 5 isempty 6 clear
// 实现的是最小堆
#pragma once
using namespace std;
class Heap
{
public:
    Heap(int length);
    ~Heap();
    void CountIndex(int index);
    void reDefine(int *&a); // 扩大数组用的
    void enqueue(int value);
    void dequeue();
    void peek();
    int size();
    bool isempty();
    void clear();
    void remove();

private:
    int length;
    int *a;
    int Pindex = 0;
    int Lindex = 0;
    int Rindex = 0;
    int backIndex = 0;
};