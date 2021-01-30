#include <bits/stdc++.h>
using namespace std;
void permutationNoDuplicates(string ques, string ans)
{
    if (ques.length() == 0)
    {
        cout << ans << "\n";
        return;
    }
    for (int i = 0; i < ques.length(); i++)
    {
        char ch = ques[i];
        string ros = ques.substr(0, i) + ques.substr(i + 1);

        bool flag = true;

        for (int j = i + 1; j < ques.length(); j++)
        {
            if (ques[j] == ch)
            {
                flag = false;
            }
        }

        if (flag)
            permutationNoDuplicates(ros, ans + ch);
    }
}
int main()
{
    string str;
    cin >> str;
    sort(str.begin(), str.end());
    permutationNoDuplicates(str, "");
    return 0;
 }
