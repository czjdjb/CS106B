#include <iostream>
#include <vector>
#include <random>
#include <chrono> //计时用的库
using namespace std;
// 没有ai的话表示写的可以不用ai进行大改 只是用ai小改了一下
// 大概速率是 1204 1204 355 24 24
void ChoseSort(vector<int> &originData)
// 手搓的
{
    int temp;
    int num1;
    int num2 = 1;
    int flag = 0;
    for (int i = 0; i < originData.size(); i++)
    {
        num1 = i;
        for (int j = i + 1; j < originData.size(); j++)
        {
            if (originData[i] > originData[j] && originData[num2] >= originData[j])
            {
                num2 = j;
                flag = 1;
            }
        }
        if (flag == 1)
        {
            temp = originData[num1];
            originData[num1] = originData[num2];
            originData[num2] = temp;
            flag = 0;
        }
    }
}
// ai写的
void ChoseSortAi(vector<int> &originData)
{
    for (int i = 0; i < originData.size() - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < originData.size(); j++)
        {
            if (originData[j] < originData[minIndex])
            {
                minIndex = j;
            }
        }
        swap(originData[i], originData[minIndex]);
    }
}
void InsertSort(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int key = arr[i]; // 当前要插入的元素
        int j = i - 1;

        // 比 key 大的元素全部往后挪一位
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // 插入到正确位置
        arr[j + 1] = key;
    }
}
void printVector(vector<int> a)
{
    cout << "Vector = ";
    for (int x : a)
    {
        cout << x << " ";
    }
    cout << endl;
}
int Min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
int partition(vector<int> &arr, int low, int high)
{
    int pivotIndex = low + rand() % (high - low + 1);
    swap(arr[pivotIndex], arr[high]);
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
}
void MergeVector(vector<int> &a, vector<int> &b, vector<int> &Result)
{
    int count1 = 0;
    int count2 = 0;
    // printVector(a);
    // printVector(b);
    while (count1 < a.size() && count2 < b.size())
    {
        if (a[count1] <= b[count2])
        {
            // cout << a[count1] << " ";
            Result.push_back(a[count1]);
            count1++;
        }
        else
        {
            // cout << b[count2] << " ";
            Result.push_back(b[count2]);
            count2++;
        }
    }
    if (count1 == a.size())
    {
        for (int i = count2; i < b.size(); i++)
        {
            // cout << b[i] << " ";
            Result.push_back(b[i]);
        }
    }
    else if (count2 == b.size())
    {
        for (int i = count1; i < a.size(); i++)
        {
            // cout << a[i] << " ";
            Result.push_back(a[i]);
        }
    }
    // cout << endl;
}
vector<int> MergeSort(const vector<int> &originData)
{
    if (originData.size() <= 1)
        return originData;
    vector<int> Result;
    vector<int> aVector;
    vector<int> bVector;
    int middle = originData.size() / 2;
    for (int i = 0; i < middle; i++)
    {
        aVector.push_back(originData[i]);
    }
    for (int i = middle; i < originData.size(); i++)
    {
        bVector.push_back(originData[i]);
    }
    aVector = MergeSort(aVector);
    bVector = MergeSort(bVector);
    MergeVector(aVector, bVector, Result);
    // for (int i = 0; i < Result.size(); i++)
    // {
    //     cout << Result[i] << " ";
    // }
    // cout << endl;
    return Result;
}
int main(void)
{
    // 生成数据
    vector<int> originData;
    vector<int> finalData;
    int dataLength = 10000;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, dataLength);
    for (int i = 0; i < dataLength; i++)
    {
        originData.push_back(dist(gen));
    }
    // for (int x : originData)
    // {
    //     cout << x << endl;
    // }
    // cout << endl
    //      << endl;
    // cout << "生成 " << originData.size() << " 个随机数" << endl;
    // auto start1 = chrono::high_resolution_clock::now();
    // ChoseSort(originData);
    // // 调用你的函数
    // auto end1 = chrono::high_resolution_clock::now();
    // auto duration1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1);
    // cout << "选择排序耗时: " << duration1.count() << " ms" << endl;

    // auto start2 = chrono::high_resolution_clock::now();
    // ChoseSortAi(originData);
    // auto end2 = chrono::high_resolution_clock::now();
    // auto duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2);
    // cout << "选择排序(ai)耗时: " << duration2.count() << " ms" << endl;

    // auto start3 = chrono::high_resolution_clock::now();
    // InsertSort(originData);
    // auto end3 = chrono::high_resolution_clock::now();
    // auto duration3 = chrono::duration_cast<chrono::milliseconds>(end3 - start3);
    // cout << "插入排序耗时: " << duration3.count() << " ms" << endl;

    auto start4 = chrono::high_resolution_clock::now();
    finalData = MergeSort(originData);

    auto end4 = chrono::high_resolution_clock::now();
    auto duration4 = chrono::duration_cast<chrono::milliseconds>(end4 - start4);
    cout << "归并排序耗时: " << duration4.count() << " ms" << endl;

    // auto start5 = chrono::high_resolution_clock::now();
    // finalData = quickSort(originData);
    // auto end5 = chrono::high_resolution_clock::now();
    // auto duration5 = chrono::duration_cast<chrono::milliseconds>(end5 - start5);
    // cout << "归并排序耗时: " << duration5.count() << " ms" << endl;

    // for (int x : finalData)
    // {
    //     cout << x << endl;
    // }
    return 0;
}