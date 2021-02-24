#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
bool balancedParenthesis(string str)
{
    stack<char> s;
    for (int i = 0; i < str.size(); i++)
    {
        char c = str[i];
        if (c == '(' || c == '{' || c == '[')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            if (s.empty() || s.top() != '(')
            {
                return false;
            }
            s.pop();
        }
        else if (c == '}')
        {
            if (s.empty() || s.top() != '{')
            {
                return false;
            }
            s.pop();
        }
        else if (c == ']')
        {
            if (s.empty() || s.top() != '[')
            {
                return false;
            }
            s.pop();
        }
    }
    return s.empty();
}
int main()
{
    string str;
    cin >> str;
    bool ans = balancedParenthesis(str);
    if (ans)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
