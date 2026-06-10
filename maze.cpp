#include <fstream>
#include <string>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <vector>
using namespace std;
// 空处 0 起点 10 终点100 墙 99 终点路径标注 1 经过标记为2
// 对应   空格    S      E      #             o
typedef struct
{
    int row, column;
} axisMap;

bool isEqual(const axisMap &a, const axisMap &b)
{
    return a.row == b.row && a.column == b.column;
}
// operator保证让其他函数值知道如何比较axis的逻辑算法
bool operator==(const axisMap &a, const axisMap &b)
{
    return isEqual(a, b);
}

bool operator<(const axisMap &a, const axisMap &b)
{
    if (a.row != b.row)
        return a.row < b.row;
    return a.column < b.column;
}
set<axisMap> allSet; // 全局的 operator< 生效，不需要传比较函数
void printQueue(queue<axisMap> q)
{ // 传值，不破坏原队列
    while (!q.empty())
    {
        cout << "(" << q.front().row << ", " << q.front().column << ") ";
        q.pop();
    }
    cout << endl;
}
void TransMap();
int JudgeStruct(axisMap a, axisMap b)
{
    if (a.row == b.row && a.column == b.column)
        return 1;
    else
        return 0;
}
void PrintMap(const vector<vector<int>> &mazeMap)
{
    for (int i = 0; i < mazeMap.size(); i++)
    {
        for (int j = 0; j < mazeMap[i].size(); j++)
        {
            cout << mazeMap[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}
void openFile(string filename, vector<vector<int>> &mazeMap)
{
    ifstream file;
    file.open(filename);
    if (!file.is_open())
    {
        cout << "打开失败" << endl;
        return;
    }
    string line;
    int j = 0;
    while (getline(file, line) && j < mazeMap.size())
    {
        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] == '#')
                mazeMap[j][i] = 99;
        }
        j++;
    }
    file.close();
    // PrintMap(mazeMap);
}
void MoveChess(const vector<vector<int>> &mazeMap, queue<axisMap> &allQueue, set<axisMap> &allSet,
               vector<vector<int>> &mazeMapAnswer, int &flag)
{
    axisMap temp = allQueue.front();
    if (temp.row < 21 && mazeMap[temp.row + 1][temp.column] != 99) // 玩家下移
    {
        temp.row += 1;
        if (allSet.find(temp) == allSet.end())
        {
            // 更新
            // queue更新
            allQueue.push(temp);
            // set更新
            allSet.insert(temp);
            // answer更新
            mazeMapAnswer[temp.row][temp.column] = 1;
            if (mazeMap[temp.row][temp.column] == 100)
            {
                flag = 1;
                return;
            }
        }
        // 让temp恢复原样
        temp.row -= 1;
    }
    if (temp.row > 0 && mazeMap[temp.row - 1][temp.column] != 99) // 玩家上移
    {
        temp.row -= 1;
        if (allSet.find(temp) == allSet.end())
        {
            // 更新
            // queue更新
            allQueue.push(temp);
            // set更新
            allSet.insert(temp);
            // answer更新
            mazeMapAnswer[temp.row][temp.column] = 1;
            if (mazeMap[temp.row][temp.column] == 100)
            {
                flag = 1;
                return;
            }
        }
        // 让temp恢复原样
        temp.row += 1;
    }
    if (temp.column < 30 && mazeMap[temp.row][temp.column + 1] != 99) // 玩家右移
    {
        temp.column += 1;
        if (allSet.find(temp) == allSet.end())
        {
            // 更新
            // queue更新
            allQueue.push(temp);
            // set更新
            allSet.insert(temp);
            // answer更新
            mazeMapAnswer[temp.row][temp.column] = 1;
            if (mazeMap[temp.row][temp.column] == 100)
            {
                flag = 1;
                return;
            }
        }
        // 让temp恢复原样
        temp.column -= 1;
    }
    if (temp.column > 0 && mazeMap[temp.row][temp.column - 1] != 99) // 玩家左移
    {
        temp.column -= 1;
        if (allSet.find(temp) == allSet.end())
        {
            // 更新
            // queue更新
            allQueue.push(temp);
            // set更新
            allSet.insert(temp);
            // answer更新
            mazeMapAnswer[temp.row][temp.column] = 1;
            if (mazeMap[temp.row][temp.column] == 100)
            {
                flag = 1;
                return;
            }
        }
        // 让temp恢复原样
        temp.column += 1;
    }
}
void FinalChess(vector<vector<int>> &mazeMap, queue<axisMap> &allQueue, set<axisMap> &allSet,
                vector<vector<int>> &mazeMapAnswer)
{
    int maxNum = 1000;
    int flag = 0;
    int count = 0;
    int step = 0;
    while (flag == 0 && step < maxNum)
    {
        MoveChess(mazeMap, allQueue, allSet, mazeMapAnswer, flag);
        allQueue.pop();
        step++;
        // cout << step;
        // 看queue是否空
        // cout << "queue" << endl;
        // printQueue(allQueue);
        // 遍历set
        // cout << "set" << endl;
        // for (const axisMap &word : allSet)
        // {
        //     cout << "row = " << word.row << " column = " << word.column << endl;
        // }
        // cout << endl;
        // cout << endl;
    }
    if (step >= maxNum)
    {
        cout << "step over!" << endl;
        return;
    }
    for (int i = 0; i < mazeMap.size(); i++)
    {
        for (int j = 0; j < mazeMap[i].size(); j++)
        {
            if (mazeMapAnswer[i][j] == 1)
            {
                mazeMap[i][j] = mazeMapAnswer[i][j];
                PrintMap(mazeMap);
            }
        }
    }
}
int main()
{
    vector<vector<int>> mazeMap(21, vector<int>(31, 0));
    vector<vector<int>> mazeMapAnswer(21, vector<int>(31, 0));
    string filename = "E:\\csStudy\\gitcode\\CS106B\\maze.txt";
    mazeMap[1][0] = 10;    // 设置起点
    mazeMap[20][29] = 100; // 设置终点
    queue<axisMap> allQueue;
    set<axisMap> allSet;
    axisMap initM;
    // 初始化
    // int flag = 0;
    initM.row = 1;
    initM.column = 0;
    allQueue.push(initM);
    allSet.insert(initM);
    mazeMapAnswer[initM.row][initM.column] = 1;
    openFile(filename, mazeMap);
    // cout << "mazeMap[3][5] = " << mazeMap[3][5];
    FinalChess(mazeMap, allQueue, allSet, mazeMapAnswer);
    // MoveChess(mazeMap, allQueue, allSet, mazeMapAnswer, flag);
    // PrintMap(mazeMapAnswer);
    return 0;
}