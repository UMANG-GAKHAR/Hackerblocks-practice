#include <bits/stdc++.h>
using namespace std;
#define ppi pair<int, pair<int, int>> 
vector<int> mergeKSortedArrays(vector<vector<int>> v)
{
    int k = v.size();
    int n = v[0].size();
    vector<int> res;
    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
    for (int i = 0; i < k; i++)
    {
        //Push the first elements of all the rows into the PQ with their row and column number
        pq.push({v[i][0], {i, 0}});
    }
    while (!pq.empty())
    {
        //Take the smallest element out of PQ
        //Insert it into final result and push the next element of its row into the PQ
        ppi t = pq.top();
        pq.pop();
        res.push_back(t.first);
        int rowNo = t.second.first;
        int colNo = t.second.second;
        if (colNo < n - 1)
        {
            //Check whether the current element is last element of its row or not. If so , do nothing.
            pq.push({v[rowNo][colNo + 1], {rowNo, colNo + 1}});
        }
    }

    return res;
}
int main()
{
    int k;  //No of rows
    int n;  //No of cols
    cin >> k >> n;
    vector<vector<int>> v(k, vector<int>(n));
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    vector<int> res = mergeKSortedArrays(v);

    for (int x : res)
    {
        cout << x << " ";
    }
    return 0;
}
