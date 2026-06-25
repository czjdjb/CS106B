#pragma once
#include <string>
using namespace std;
struct TreeNode
{
    string data;
    TreeNode *leftNode;
    TreeNode *rightNode;
};
class Tree
{
public:
    Tree(string newData);
    ~Tree();
    void PreOrder();

    void InOrder();
    void PostOrder();
    void addNode(string newNode);
    void removeNode();

private:
    TreeNode *head;
    void preOrderHelper(TreeNode *node);
    void inOrderHelper(TreeNode *node);
    void postOrderHelper(TreeNode *node);
};