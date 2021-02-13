#include <bits/stdc++.h>
using namespace std;
void printSubsequences(string inp, string out)
{
    if (inp.size() == 0)
    {
        cout << out << " ";
        return;
    }

    char ch = inp[0];
    inp = inp.substr(1);
    printSubsequences(inp, out);
    printSubsequences(inp, out + ch);
}

int main()
{
    string s;
    cin >> s;

    printSubsequences(s, "");

    cout << endl;

    int n = (1 << s.size());
    cout << n << endl;
    return 0;
}
