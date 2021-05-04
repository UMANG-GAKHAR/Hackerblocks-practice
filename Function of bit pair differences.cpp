#include <bits/stdc++.h> 
using namespace std; 
#define ll long long
ll sumBitDifferences(ll a[], ll n) { 
    ll ans = 0; 
    for (ll i=0; i<32;i++) { 
        ll count=0; 
        for (ll j=0; j<n; j++) {
            if ((a[j] &(1<<i))) {
                count++; 
            }
        }
        ans += (count*(n-count)*2); 
    } 
    return ans; 
} 
int main() {
       ll t;
       cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll a[n];
        for(ll i=0;i<n;++i) {
            cin >> a[i];
        }
        cout << sumBitDifferences(a,n) << "\n";
    } 
    return 0; 
} 
