#include <bits/stdc++.h>
using namespace std;
vector<int> allIndices(const vector<int> &v, int key, int i, int idx)
{
    if (i == v.size())
    {
        return vector<int>(idx);
    }

    if (v[i] == key)
    {
        vector<int> remainingAns = allIndices(v, key, i + 1, idx + 1);
        remainingAns[idx] = i;
        return remainingAns;
    }
    else
    {
        return allIndices(v, key, i + 1, idx);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int key;
    cin >> key;

    vector<int> ans = allIndices(v, key, 0, 0);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
