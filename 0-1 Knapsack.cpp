#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[1005][1005];
ll knapsack(ll n, ll w, ll *weights, ll *prices)
{
    if (n == 0 || w == 0)
    {
        return 0;
    }
    if (dp[n][w] != -1)
    {
        return dp[n][w];
    }
    ll include = 0;
    ll exclude = 0;

    if (weights[n - 1] <= w)
    {
        include = prices[n - 1] + knapsack(n - 1, w - weights[n - 1], weights, prices);
    }
    exclude = knapsack(n - 1, w, weights, prices);
    dp[n][w] = max(include, exclude);
    return dp[n][w];
}
int main()
{
    ll n, w;
    cin >> n >> w;
    ll weights[1005] = {0};
    ll prices[1005] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << knapsack(n, w, weights, prices);
    return 0;
}
