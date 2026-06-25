// printtree ->traversal 1 前序 2中序 3后序  freetree
// 用binaryTree的方式add节点 一样大的按小处理 小是在左节点
// tree 的递归写法很关键 用一个help的函数帮助 调用内部的head class是调用函数方法 而方法引出head
// removeNode 在14 15中实现
#include <iostream>
#include <string>
#include <vector>
#include "13.Tree.h"
using namespace std;
Tree::Tree(string newData)
{
    head = new TreeNode;
    head->data = newData;
    head->leftNode = nullptr;
    head->rightNode = nullptr;
}
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
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
bool JudgeString(string &oString, string &jString)
{
    int flag = 0;
    if (oString.size() != jString.szie())
    {
        return false;
    }
    for (int i = 0; i < oString.size(); i++)
    {
        if (oString[i] = jString[i])
            flag = 1;
    }
    if (flag == 1)
        return false;
    else
        return true;
}
void Tree::addNode(string newData)
{
    bool x;
    TreeNode *newNode = new TreeNode;
    newNode->data = newData;
    newNode->leftNode = nullptr;
    newNode->rightNode = nullptr;
    TreeNode *moveNode = head;
    while (1)
    {
        cout << "moveNode->data=" << moveNode->data << endl;
        cout << "newData=" << newNode->data << endl;
        cout << endl;
        x = MoreString(moveNode->data, newNode->data);
        if (!x)
        {
            if (moveNode->leftNode == nullptr)
            {
                moveNode->leftNode = newNode;
                break;
            }
            else
                moveNode = moveNode->leftNode;
        }
        else
        {
            if (moveNode->rightNode == nullptr)
            {
                moveNode->rightNode = newNode;
                break;
            }
            else
                moveNode = moveNode->rightNode;
        }
    }
}
void Tree::preOrderHelper(TreeNode *node)
{
    if (!node)
        return; // 这里的判断要记住 因为不管是左节点 还是右节点 都是nullptr 所以可以都把终止条件设为nullptr
    cout << node->data << " ";
    preOrderHelper(node->leftNode);
    preOrderHelper(node->rightNode);
}
void Tree::inOrderHelper(TreeNode *node)
{
    if (!node)
        return;
    inOrderHelper(node->leftNode);
    cout << node->data << " ";
    inOrderHelper(node->rightNode);
}
void Tree::postOrderHelper(TreeNode *node)
{
    if (!node)
        return;
    postOrderHelper(node->leftNode);
    postOrderHelper(node->rightNode);
    cout << node->data << " ";
}
void Tree::PreOrder()
{
    preOrderHelper(head);
}
void Tree::InOrder()
{
    inOrderHelper(head);
}
void Tree::PostOrder()
{
    postOrderHelper(head);
}
// void Tree::removeNode(string removeData)
// {
//     TreeNode *moveNode = head;

// }
Tree::~Tree()
{
    // 用后序 因为节点不提前删除
}
int main()
{
    vector<string> fruits = {"coconut",
                             "banana", "durian", "strawberry", "taro"};
    string fruit = "pineapple";

    Tree t(fruit);

    for (string x : fruits)
    {
        t.addNode(x);
    }

    t.PreOrder();
    cout << endl;
    t.InOrder();
    cout << endl;
    t.PostOrder();
    return 0;
}
