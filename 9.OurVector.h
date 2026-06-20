// 实现功能 add(value) insert(index,value) get(index) remove size isEmpty
//  expand(创造新的指针 释放旧的指针 内容复制)（在private）如果超出大小了还要扩容
#pragma once
using namespace std;
class OurVector
{
public:
    // 此处不传入*a 是因为如果传入*a 那么地址绑定的就是外面传入的数组 而不是private
    // 里面new出来的数组了
    OurVector(int length)
    {
        this->length = length;
        this->a = new int[length];
    }
    ~OurVector()
    {
        delete[] a;
    } // 使用析构器去清除分配的地址
    void Redfine(int *&a);
    int size();
    void printVector();
    void add(int value);
    void insert(int index, int value);
    int get(int index);
    void remove(int value);
    bool isEmpty();

private:
    int length;
    int index = 0; // backIndex
    int *a;
};