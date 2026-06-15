// 目标让一个9个字母的词汇每次删除一个字母都是一个合法词汇 随机位置
// startling → starling → staring → string → sting → sing → sin → in → i
#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <vector>
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
void MakeUser(const set<string> &wordDic, vector<string> &allWord, string targetWord, int &flag)
{
    if (targetWord.size() == 0)
    {
        flag = 1;
        return;
    }
    if (wordDic.find(targetWord) == wordDic.end())
    {
        return;
    }
    string temp;
    for (int i = 0; i < targetWord.length(); i++)
    {
        allWord.push_back(targetWord);
        temp = targetWord[i];
        string rest = targetWord.substr(0, i) + targetWord.substr(i + 1);
        MakeUser(wordDic, allWord, rest, flag);
        if (flag == 1)
            return;
        else if (flag == 0)
        {
            allWord.pop_back();
        }
    }
    // 此处如果不对allWord加上回溯效果 则allWord会把所有的可能都加进去 可以注释掉下面的试试
}
void MakeWord(const set<string> &wordDic, vector<string> &allWord, string targetWord, int flag)
{
    return MakeUser(wordDic, allWord, targetWord, flag);
}
int main(void)
{
    string filename = "E:\\csStudy\\gitcode\\CS106B\\EnglishWords.txt";
    set<string> wordDic;
    vector<string> allWord;
    string targetWord = "startling";
    int flag = 0;
    openFile(filename, wordDic);
    MakeWord(wordDic, allWord, targetWord, flag);
    // if (flag == 0)
    // {
    //     cout << "not exist" << endl;
    //     return 0;
    // }
    for (string x : allWord)
    {
        cout << x << endl;
    }
}