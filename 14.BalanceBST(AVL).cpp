// 14 15都是用来实现set的
// contain add remove clear size isempty printsetcontent
#include <iostream>
#include <string>
#include <vector>
#include <climits> //用于设置最大值
#include "14.OurSet(BST).h"
using namespace std;
Set::Set(int newData)
{
    Avl *head = new Avl;
    head->data = newData;
    head->leftNode = nullptr;
    head->rightNode = nullptr;
    head->height = 1;
}
Set::~Set()
{
}
int max(Avl *a, Avl *b)
{
    if (a == nullptr)
        return b->height;
    else if (b == nullptr)
        return a->height;
    if (a->height > b->height)
        return a->height;
    else
        return b->height;
}
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
int MinusHeight(Avl *a, Avl *b)
{
    int aH;
    int bH;
    int minus;
    if (a == nullptr)
    {
        aH = 0;
    }
    else
    {
        aH = a->height;
    }
    if (b == nullptr)
    {
        bH = 0;
    }
    else
    {
        bH = b->height;
    }
    minus = aH - bH;
    return minus;
}
bool MoreString(string &oString, string &jString)
{
    int flag = 0;
    for (int i = 0; i < min(oString.length(), jString.length()); i++)
    {
        if (oString[i] < jString[i])
            return true;
        else if (oString[i] > jString[i])
            return false;
        else
            continue;
    }
    if (oString.length() <= jString.length())
        return true;
    else
        return false;
}
Avl *Set::LLmove(Avl *rHead)
{
    Avl *rNode = rHead->leftNode;
    // rHead->leftNode = nullptr;// 这里不能nullptr 那么当左子树的左右子树都挂载就没办法处理了
    // 比如30 25 22 21 24 27 40 就会出现问题
    rHead->leftNode = rNode->rightNode;
    rNode->rightNode = rHead;
    return rNode;
}
Avl *Set::RRmove(Avl *rHead)
{
    Avl *lNode = rHead->rightNode;
    // rHead->rightNode = nullptr; // 同LLmove
    rHead->rightNode = lNode->leftNode;
    lNode->leftNode = rHead;
    return lNode;
}
Avl *Set::RLmove(Avl *rHead)
{
    Avl *rNode = rHead->rightNode;
    Avl *rlNode = rHead->rightNode->leftNode;
    Avl *newrNode = rlNode->rightNode;
    rNode->leftNode = newrNode;
    rHead->rightNode = rlNode;
    rlNode->rightNode = rNode;
    Avl *newlNode = rlNode->leftNode;
    rlNode->leftNode = rHead;
    rHead->rightNode = newlNode;
    return rlNode;
}
Avl *Set::LRmove(Avl *rHead)
{
    Avl *lNode = rHead->leftNode;
    Avl *lrNode = lNode->rightNode;
    Avl *newlNode = lrNode->leftNode;
    lNode->rightNode = newlNode;
    rHead->leftNode = lrNode;
    lrNode->leftNode = lNode;
    Avl *newrNode = lrNode->rightNode;
    rHead->leftNode = newrNode;
    lrNode->rightNode = rHead;
    return lrNode;
}
void Set::ZeroMove(Avl *rHead, Avl *fHead, Avl *newTop)
{
    if (rHead->data < fHead->data)
    {
        fHead->leftNode = nullptr;
        fHead->leftNode = newTop;
    }
    else

    {
        fHead->rightNode = nullptr;
        fHead->rightNode = newTop;
    }
}
void Set::AvlBalance(Avl *rHead, int flag, Avl *fHead)
{
    // Avl *newTop = new Avl;
    // 此处内存泄漏 因为new了一块内存 但是下面直接赋值给了转移函数的返回值了 所以可以直接不初始化
    Avl *newTop;
    switch (flag)
    {
    case 1:
        newTop = LLmove(rHead);
        ZeroMove(rHead, fHead, newTop);
        break;
    case 2:
        newTop = RRmove(rHead);
        ZeroMove(rHead, fHead, newTop);
        break;
    case 3:
        newTop = LRmove(rHead);
        ZeroMove(rHead, fHead, newTop);
        break;
    case 4:
        newTop = RLmove(rHead);
        ZeroMove(rHead, fHead, newTop);
        break;
    default:
        break;
    }
}
Avl *Set::addHelper(int newData, Avl *rHead, Avl *fHead)
{

    // BST迭代写法见13 这里尝试递归写法
    if (!rHead)
    {
        Avl *newNode = new Avl;
        newNode->data = newData;
        newNode->leftNode = nullptr;
        newNode->rightNode = nullptr;
        newNode->height = 1;
        return newNode;
    }
    int minus;
    Avl *tempNode = fHead;
    fHead = rHead;
    if (newData < rHead->data)
    {
        Avl *newNode1 = addHelper(newData, rHead->leftNode, fHead);
        // 不能直接++ 因为如果两个子节点一个在左边 一个在右边 那么+2 就是错误的 实际应该+1
        //  rHead->height++;
        rHead->leftNode = newNode1;
    }
    else
    {
        Avl *newNode1 = addHelper(newData, rHead->rightNode, fHead);
        rHead->rightNode = newNode1;
    }
    rHead->height = max(rHead->leftNode, rHead->rightNode) + 1;
    minus = MinusHeight(rHead->leftNode, rHead->rightNode);
    if (minus > 1 || minus < -1)
    {
        // Avl *moveNode = new Avl;
        if (minus > 0)
        {
            // moveNode = moveNode->leftNode;
            minus = MinusHeight(rHead->leftNode, rHead->rightNode);
            if (minus > 0)
            {
                AvlBalance(rHead, 1, fHead); // LL
            }
            else
            {
                AvlBalance(rHead, 3, fHead); // LR
            }
        }
        else
        {
            // moveNode = moveNode->rightNode;
            minus = MinusHeight(rHead->leftNode, rHead->rightNode);
            if (minus > 0)
            {
                AvlBalance(rHead, 4, fHead); // RL
            }
            else
            {
                AvlBalance(rHead, 2, fHead); // RR
            }
        }
    }
    return rHead;
}
Avl *Set::add(int newData)
{
    // 0号节点保证 front node 可以传下去
    // 通过节点的数值比较来判断是左节点还是右节点连接
    Avl *zeroNode = new Avl;
    zeroNode->leftNode = head;
    zeroNode->data = INT_MAX;
    return addHelper(newData, head, zeroNode);
}
int main(void)
{
    vector<int> data = {30, 25, 40, 22, 27, 35, 50, 21, 24, 26, 28};

    return;
}