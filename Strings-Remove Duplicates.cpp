#include <bits/stdc++.h>
using namespace std;
string removeDuplicate(string s)
{
    if (s.size() <= 1)
    {
        return s;
    }
    string ros = removeDuplicate(s.substr(1));

    if (s[0] == ros[0])
    {
        return ros;
    }

    return s[0] + ros;
}
int main()
{
    string s;
    cin >> s;

    cout << removeDuplicate(s) << endl;

    return 0;
}
