#include <bits/stdc++.h>
using namespace std;
vector<string> table = {" ", ".+@$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> searchIn = {
    "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
    "utkarsh", "divyam", "vidhi", "sparsh", "akku"};
void phoneKeypad(string inp, string out)
{
    //Base case
    if (inp.size() == 0)
    {
        for (string ss : searchIn)
        {
            if (ss.find(out) != ss.npos)
            {
                cout << ss << endl;
            }
        }
        return;
    }

    //Rec case
    char ch = inp[0];
    string ros = inp.substr(1);
    string code = table[ch - '0'];

    for (int i = 0; i < code.length(); i++)
        phoneKeypad(ros, out + code[i]);
}

int main()
{
    string input;
    cin >> input;

    string output;
    phoneKeypad(input, output);
    return 0;
}
