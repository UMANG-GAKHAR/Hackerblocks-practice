#include <iostream>
#include <cstring>
using namespace std;
string table[] = {" ", ".+@$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
void phoneKeypad(string inp, string out)
{
    if (inp.size() == 0)
    {
        cout << out << "\n";
        return;
    }
    //Rec case
    int r = inp[0] - '0';
    for (unsigned int k = 0; k < table[r].length(); k++)
    {
        char ch = table[r][k];
        phoneKeypad(inp.substr(1), out + ch);
    }
}
int main()
{
    string input;
    cin >> input;
    phoneKeypad(input, "");
    return 0;
}
