#include <iostream>
using namespace std;
#define ll long long int
int main() {
    ll testCases;
    cin >> testCases;
    while(testCases--){
        ll n ;
        cin >> n;
        ll c[n];
        for(ll i=0;i<n;i++){
            cin >> c[i];
        }
        ll l[n];
        for(ll i=0;i<n;i++){
            cin >> l[i];
        }
        ll currentCost = c[0];
        ll total = 0 ;        
        for(ll i=0;i<n;i++){
            currentCost = min(currentCost,c[i]);
            total = total + currentCost*l[i];
        }
        cout << total << endl ;
    }
    return 0;
}
