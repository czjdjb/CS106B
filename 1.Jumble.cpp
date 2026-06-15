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
void WordUser(const set<string> &wordDic, set<string> &allWords, string targetGroup, string tempWord)
{
    if (targetGroup.empty())
    {
        // cout << tempWord << endl;
        if (wordDic.find(tempWord) != wordDic.end())
        {
            allWords.insert(tempWord);
            return;
        }
        return;
    }
    char temp;
    for (int i = 0; i < targetGroup.size(); i++)
    {
        temp = targetGroup[i];
        string rest = targetGroup.substr(0, i) + targetGroup.substr(i + 1);
        // substr （a，b） 当b为default时候 默认从a取到末尾 当a超出size时候 返回空字符串
        //  WordUser(wordDic, allWords, targetGroup.erase(i, 1), tempWord + temp);
        // 使用erase的时候 注意
        // 1.对应string的size会发生变化导致循环错误
        // 2.即使使用 targetGroup+=temp; 进行重塑 仍然会让原string内部的索引位置产生错误
        // 所以最佳方法应使用substr 即生成子串来传输 避免逻辑错误
        WordUser(wordDic, allWords, rest, tempWord + temp);
    }
}
void WordGroup(set<string> &wordDic, set<string> &allWords, string &tagretGroup)
{
    return WordUser(wordDic, allWords, tagretGroup, "");
}

int main()
{
    string filename = "E:\\csStudy\\gitcode\\CS106B\\EnglishWords.txt";
    set<string> wordDic;
    set<string> allGrops;
    set<string> allWords;
    string targetGroup = "cat"; // 注意输入要小写 因为dic里只有小写 避免set遍历时候无法匹配
    openFile(filename, wordDic);
    WordGroup(wordDic, allWords, targetGroup);
    // cout << endl;
    for (string x : allWords)
    {
        cout << x << endl;
    }
    return 0;
}