#include <iostream>
#include <vector>
using namespace std;
int binarySV1(vector<int> allVector, int input, int midLocation) // 传递的int是index
{
    int temp = midLocation;
    midLocation /= 2;
    cout << "size = " << allVector.size() << endl;
    if (allVector.size() == 1)
    {
        if (allVector.front() == input)
            return midLocation;
        else
            return -10000;
    }
    if (input > allVector[temp])
    {
        allVector.erase(allVector.begin(), allVector.begin() + temp);
        return temp + binarySV1(allVector, input, midLocation);
    }
    else if (input < allVector[temp])
    {
        allVector.erase(allVector.begin() + temp, allVector.begin() + allVector.size());
        return temp - binarySV1(allVector, input, midLocation);
    }
    else
        return midLocation;
}
int binaryUser(vector<int> allVector, int input)
{
    int midLocation;
    int temp;
    int tempSize = 0;
    midLocation = allVector.size() / 2;
    if (allVector.size() % 2 == 0) // 把偶数的数列变成奇数的然后再处理
    {
        midLocation -= 1;
        if (allVector[midLocation] == input)
        {
            return midLocation;
        }
        else if (allVector[midLocation - 1] == input)
            return midLocation - 1;
        else
        {
            temp = allVector[midLocation] + allVector[midLocation - 1];
            temp /= 2;
            if (temp == input || temp == (input + 1))
                return -1;
            allVector.erase(allVector.begin() + midLocation);
            allVector[midLocation - 1] = temp;
            midLocation -= 1;
        }
    }
    return binarySV1(allVector, input, midLocation) + 1;
}
int binarySearch(const vector<int> &v, int target)
{
    int left = 0, right = v.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (v[mid] == target)
            return mid;
        if (v[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
int binarySearchRecursion(const vector<int> &v, int target, int left, int right)
{
    if (left > right)
        return -1;

    int mid = left + (right - left) / 2;

    if (v[mid] == target)
        return mid;
    if (v[mid] < target)
        return binarySearchRecursion(v, target, mid + 1, right);
    else
        return binarySearchRecursion(v, target, left, mid - 1);
}
int main()
{
    vector<int> allVectorOdd = {3, 7, 11, 17, 22, 28, 38, 42,
                                50, 54, 65, 76, 83, 89, 91};
    vector<int> allVectorEven = {5, 8, 12, 14, 19, 26, 30, 33, 47,
                                 55, 60, 69, 72, 81, 88, 95};
    int result;
    int input = 7;
    // result = binaryUser(allVectorOdd, input); // 自己写的 错误且逻辑混乱 retun的值不对 并且因为erase导致index错误 计算会非常复杂
    // result = binarySearch(allVectorOdd, input); //迭代办法
    result = binarySearchRecursion(allVectorOdd, input, 0, allVectorOdd.size() - 1); // 递归办法
    if (result < 0)
        cout << "cant find";
    else
        cout << "index = " << result;
    return 0;
}