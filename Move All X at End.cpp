#include <bits/stdc++.h>
using namespace std;

string move(string s)
{
    if (s.size() <= 1)
        return s;

    string ros = s.substr(1);
    ros = move(ros);
    if (s[0] == 'x')
        return ros + s[0];
    else
        return s[0] + ros;
}

int main()
{
    string s;
    cin >> s;

    cout << move(s);

    return 0;
}
