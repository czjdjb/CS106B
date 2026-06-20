#pragma once
#include <vector>
#include <random>
using namespace std;
class RandomBags
{
public:
    void addElem(int value);
    void RemoveAndRandom(int value);
    int VectorSize();
    bool isEmpty();
    void PrintRb();

private:
    vector<int> elems;
};