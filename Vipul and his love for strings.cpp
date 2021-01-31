#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nn 2000005
string a,b;
ll n,m,k;
ll dp[1005][ 1005 ][ 11 ][ 2 ];
ll solve ( ll ia, ll ib, ll subs, ll cont )
{
    if ( subs < 0 )
        return INT_MIN;
    if ( ia == a.size() or ib == b.size() )
    {
        if ( subs == 0 )
        {
            return 0;
        }
        else
            return INT_MIN;
    }
    if ( dp[ia][ib][subs][cont] != - 1)
        return dp[ia][ib][subs][cont];
    ll ret = INT_MIN;
    if ( cont == 1 )
    {
        if ( a[ia] == b[ib] )
        {
            ret = max(1+solve(ia+1,ib+1,subs,1),max(solve(ia+1,ib,subs-1,0),solve(ia,ib+1,subs-1,0)));
            ret = max(ret,1+solve(ia+1,ib+1,subs-1,0));
        }
        else
            ret = max(solve(ia+1,ib,subs,0),solve(ia,ib+1,subs,0));
    }
    else
    {
        if ( a[ia] == b[ib] )
        {
            ret = max(1+solve(ia+1,ib+1,subs-1,1),max(solve(ia+1,ib,subs,0),solve(ia,ib+1,subs,0)));
            ret = max(ret,1+solve(ia+1,ib+1,subs-1,0));
        }
        else
            ret = max(solve(ia+1,ib,subs,0),solve(ia,ib+1,subs,0));
    }   
    return dp[ia][ib][subs][cont] = ret;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    memset(dp,-1,sizeof dp);
    cin >> n >> m >> k;
    cin >> a >> b;
    cout << solve(0,0,k,0);
}
