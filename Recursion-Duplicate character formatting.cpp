#include <bits/stdc++.h>
using namespace std;
string duplicateChar(string s)
{
    if (s.size() <= 1)
    {
        return s;
    }

    string ros = duplicateChar(s.substr(1));

    if (s[0] == ros[0])
    {
        return s[0] + string("*") + ros;
    }

    return s[0] + ros;
}
int main()
{
    string s;
    cin >> s;
    cout << duplicateChar(s) << endl;
    return 0;
}
