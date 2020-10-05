#include <bits/stdc++.h> 
using namespace std; 
#define ll long long



void printLeapCodes(ll num, ll x, vector<ll> &vec)  { 
    queue<ll> q; 
    q.push(num); 

    while (!q.empty()) { 
        num = q.front(); 
        q.pop(); 
        if (num <= x) { 
            vec.push_back(num); 
            ll lastDig = num % 10; 
            if (lastDig == 0) { 
                q.push((num * 10) + (lastDig + 1)); 
            } else if (lastDig == 9) { 
                q.push((num * 10) + (lastDig - 1)); 
            } else { 
                q.push((num * 10) + (lastDig - 1)); 
                q.push((num * 10) + (lastDig + 1)); 
            } 
        } 
    } 
}
int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        vector<ll> vec; 
        vec.push_back(0);
        for(ll i=1;i<=9&&i<=n;++i) {
            printLeapCodes(i,n,vec);
        }
        sort(vec.begin(),vec.end());
        for(auto it:vec) {
            cout << it << " ";
        }
        cout << "\n";
    }
    return 0;
    }
