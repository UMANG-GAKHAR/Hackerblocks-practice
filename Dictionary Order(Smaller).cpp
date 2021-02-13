#include <bits/stdc++.h>
using namespace std;
string str;
void permute(string inp, string out)
{
    //Base case
    if (inp.size() == 0)
    {
        if (out < str)
        {
            cout << out << endl;
        }
        return;
    }

    //Recursive case
    for (int i = 0; i < inp.size(); i++)
    {
        string ros = inp.substr(0, i) + inp.substr(i + 1);
        permute(ros, out + inp[i]);
    }
}
int main()
{
    cin >> str;

    string temp = str;

    sort(temp.begin(), temp.end());

    permute(temp, "");

    return 0;
}

