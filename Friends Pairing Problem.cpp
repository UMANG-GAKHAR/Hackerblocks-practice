#include <bits/stdc++.h>
using namespace std;
long long countFriendsPairings(int n)
{
    long long dp[n+1];
    for (int i=0; i<=n; i++)
    {
        if (i <= 2)
        dp[i] = i;
        else
        dp[i] = dp[i-1] + (i-1) * dp[i-2];
    }
    return dp[n];
}
int main()
{
    int n ,t;
    cin>>t;
    while(t>0)
    {
    cin>>n;
    cout << countFriendsPairings(n) << endl;
    t--;
    }
    return 0;
}
