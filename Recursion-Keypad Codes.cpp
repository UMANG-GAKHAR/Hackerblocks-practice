#include <iostream>
#include <cstring>
using namespace std;
string keypad[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wx", "yz"};
int count = 0;
void keypadCode(string inp, string out, int i)
{
    //Base case
    if (i == inp.size())
    {
        cout << out << " ";
        count++;
        return;
    }

    //Rec case
    int r = inp[i] - '0';
    for (int k = 0; k < keypad[r].size(); k++)
    {
        char ch = keypad[r][k];
        keypadCode(inp, out + ch, i + 1);
    }
}
int main()
{
    string inp;
    cin >> inp;
    string output;
    keypadCode(inp, output, 0);
    cout << endl << count;
    return 0;
}
