#include <string>
#include <iostream>
using namespace std;
string ReverseString(string &rstring)
{
    if (rstring.empty())
        return "";
    char temp;
    temp = rstring.front();
    rstring.erase(0, 1);
    return ReverseString(rstring) + temp;
}
int main()
{
    string rstring = "wxh";
    rstring = ReverseString(rstring);
    cout << rstring;
    return 0;
}