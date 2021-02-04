#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll n;
    cin >> n;
    vector<ll> x;
    vector<ll> y;

    x.push_back(0);
    y.push_back(0);

    for(ll i=0;i<n;i++){
        ll a,b;
        cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());

    ll deltaX = 0;
    for(ll i=1;i<x.size();i++){
        ll diff = x[i] - x[i-1] - 1 ;
        deltaX = max(deltaX,diff);
    }
    ll deltaY = 0;
    for(ll i=1;i<y.size();i++){
        ll diff = y[i] - y[i-1] - 1 ;
        deltaY = max(deltaY,diff);
    }
    ll maxArea = deltaX * deltaY ;
    cout << maxArea ;
    return 0;
}
