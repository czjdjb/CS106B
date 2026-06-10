#include <fstream>
#include <string>
#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;

void openFile(string filename, set<string> &setWords)
{
    ifstream file;
    file.open(filename);
    if (!file.is_open())
    {
        cout << "打开失败" << endl;
        return;
    }

    string line;
    while (getline(file, line))
    {
        // cout << line << endl;
        setWords.insert(line);
    }
    // if (setWords.find("zyme") != setWords.end())
    // {
    //     // 找到了
    //     cout << "get it";
    // }
    file.close();
}
void MoreWordv1(const string &ori, const set<string> &setWords, set<string> &allSet, queue<string> &allqueue,
                int &flag, string string2, map<string, string> &allMap)
/**
输入onequeue这个队列 生成的词也是全部在队列里 直接弹入到最终的队列中
 */
{
    string oriTmp;
    string oriTmp1;
    for (int i = 0; i < ori.size(); i++)
    {
        oriTmp = ori;
        for (char j = 'a'; j < 'z'; j++)
        {
            oriTmp[i] = j;
            if (setWords.find(oriTmp) != setWords.end() && allSet.find(oriTmp) == allSet.end())
            {
                // queue的更新
                allqueue.push(oriTmp);
                // set的更新
                allSet.insert(oriTmp);
                // map 的更新
                // cout << oriTmp << ",\t" << ori << endl;
                allMap.insert({oriTmp, ori});
                // 判断是否遇到最终的
                if (oriTmp == string2)
                {
                    flag = 1;
                    return;
                }
                // cout << allqueue.back() << endl;
            }
        }
    }
    return;
}
void goToWord(string string1, string string2, const set<string> &wordDic)
{
    /**
    string1是输入的词 wordDic是英语词典
     */
    int endNum = 10000;
    int flag = 0;
    string temp;
    stack<string> allStack;
    map<string, string> allMap;
    set<string> allSet;     // 用于保证生成的词不会重复
    queue<string> allQueue; // 总的队列 用于弹入弹出
    // queue<string> oneQueue;
    int count = 0;
    // 初始化
    allSet.insert(string1);
    allQueue.push(string1);
    allMap.insert({string1, "end"});
    while (flag == 0 && count < endNum)
    {
        temp = allQueue.front();
        allQueue.pop();
        MoreWordv1(temp, wordDic, allSet, allQueue, flag, string2, allMap);
        // cout << flag;
    }
    if (count >= endNum)
    {
        cout << endNum << " token cant find" << endl;
        return;
    }
    count = 0;
    // 遍历set
    // for (const string &word : allSet)
    // {
    //     cout << word << " ";
    // }
    // cout << endl;
    // cout << endl;
    // 遍历map
    // for (auto &[key, value] : allMap)
    // { // C++17 结构化绑定
    //     cout << key << ": " << value << endl;
    // }
    while (1)
    {
        if (allMap.find(string2) != allMap.end())
        {
            // cout << string2 << endl;
            allStack.push(string2);
            // cout << allStack.size() << "\t" << allStack.top() << endl;
        }

        string2 = allMap.at(string2);

        if (string2 == "end")
        {
            // cout << "end the Map" << endl;
            break;
        }
        count++;
    }
    int stackNum = allStack.size();
    // cout << allStack.top() << endl;
    for (int i = 0; i < stackNum; i++)
    {
        cout << allStack.top() << endl;
        allStack.pop();
    }
    cout << "move count = " << count << endl;
    return;
}

int main()
{
    string filename = "E:\\csStudy\\gitcode\\CS106B\\EnglishWords.txt";
    set<string> wordDic;
    openFile(filename, wordDic);
    string string1 = "rug";
    string string2 = "hat";
    goToWord(string1, string2, wordDic);
    return 0;
}