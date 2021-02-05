#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll coins[10005];
ll dp[5000][5000];
ll optimalGame(ll i,ll j){
    if(i > j){
        return 0;
    }
    if(i<5000 && j<5000){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
    }
    ll pickFirst = coins[i] + min( optimalGame(i+2,j) , optimalGame(i+1,j-1) ) ;
    ll pickLast = coins[j] + min( optimalGame(i,j-2) , optimalGame(i+1,j-1) ) ;

    ll ans = max(pickFirst,pickLast);

    if(i<5000 && j<5000){
        dp[i][j] = ans ; 
    }
    return ans;
}
int main() {
    ll n;
    cin >> n;   
    for(ll i=0;i<n;i++){
        cin >> coins[i];
    }
    memset(dp,-1,sizeof(dp)) ;
    cout << optimalGame(0,n-1);
    return 0;
}
