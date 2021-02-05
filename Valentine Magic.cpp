#include <bits/stdc++.h>
using namespace std;
#define MAX 50000000000
#define ll long long int
ll dp[5005][5005];
ll valentine(vector<ll> &choc,vector<ll> &candy,ll i,ll j){
    if(i == choc.size()){
        return 0 ;
    }
    if(j == candy.size()){
        return MAX;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    ll diff = abs(choc[i] - candy[j]) ;
    ll q1 = valentine(choc,candy,i+1,j+1) + diff;     // Pair ith boy with jth girl
    ll q2 = valentine(choc,candy,i,j+1) ;                  // Do not pair

    dp[i][j] = min(q1,q2);

    return dp[i][j]; 
}
int main() {
    ll n ; //No of boys
    ll m ; //No of girls
    cin >> n >> m;
    vector<ll> choc;
    vector<ll> candy;
    for(ll i=0;i<n;i++){
        ll x;
        cin >> x;
        choc.push_back(x);
    }
    for(ll i=0;i<m;i++){
        ll x;
        cin >> x;
        candy.push_back(x);
    }
    memset(dp,-1,sizeof(dp));
    sort(choc.begin(),choc.end());
    sort(candy.begin(),candy.end());

    cout << valentine(choc,candy,0,0) ;
    return 0;
}
