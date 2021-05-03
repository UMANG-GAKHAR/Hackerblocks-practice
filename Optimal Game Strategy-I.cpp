#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll coins[40];
ll optimalGame(ll i,ll j){
    if(i > j){
        return 0;
    }
    ll pickFirst = coins[i] + min( optimalGame(i+2,j) , optimalGame(i+1,j-1) ) ;
    ll pickLast = coins[j] + min( optimalGame(i,j-2) , optimalGame(i+1,j-1) ) ;
    ll ans = max(pickFirst,pickLast);
    return ans;
}
int main() {
    int n;
    cin >> n;   
    for(int i=0;i<n;i++){
        cin >> coins[i];
    }
    cout << optimalGame(0,n-1);
    return 0;
}
