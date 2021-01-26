#include <bits/stdc++.h>
using namespace std;
int importanceOfTime(queue<int> &q, const vector<int> &arr)
{
    //arr is the ideal order
    //q is the calling order
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (q.front() == arr[i])
        {
            ans++;
            q.pop();
        }
        else
        {
            while (q.front() != arr[i])
            {
                int var = q.front();
                q.push(var);
                q.pop();
                ans++;
            }
            ans++;
            q.pop();
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << importanceOfTime(q, v);
    return 0;
}
