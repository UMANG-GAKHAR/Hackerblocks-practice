#include <bits/stdc++.h>
using namespace std;
int strToInt(string str, int number)
{
    if (str.length() == 0)
    {
        return number;
    }
    char ch = str[0];
    number = number + (ch - 48) * (int)pow(10, str.length() - 1);
    string ros = str.substr(1);
    return strToInt(ros, number);
}
int main()
{
    string str;
    cin >> str;
    int ans = strToInt(str, 0);
    cout << ans << endl;

    return 0;
}
