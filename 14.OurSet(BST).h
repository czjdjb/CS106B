//  注意不要有重复元素
// 14 15共用这个h文件 要实现的内容相同
#pragma once
#include <string>
using namespace std;
struct Avl
{
    int data;
    int height;
    Avl *leftNode;
    Avl *rightNode;
};
class Set
{
public:
    Set(int newData);
    ~Set();
    void contain();
    Avl *add(int newData);
    void remove(int newData);
    void clear();
    void size();
    void isempty();
    void printSet();

private:
    Avl *head;
    Avl *addHelper(int newData, Avl *rHead, Avl *fHead);
    Avl *LLmove(Avl *rHead);
    Avl *RRmove(Avl *rHead);
    Avl *LRmove(Avl *rHead);
    Avl *RLmove(Avl *rHead);
    void ZeroMove(Avl *rHead, Avl *fHead, Avl *newTop);
    void AvlBalance(Avl *rHead, int flag, Avl *fHead);
};