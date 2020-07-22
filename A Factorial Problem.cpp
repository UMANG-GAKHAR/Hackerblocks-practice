#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n, k, x = LLONG_MAX;
        cin >> n >> k;
        for (ll prime = 2; (prime*prime <= k) && (k > 1); prime++) {
            ll kcount = 0;
            if (k % prime == 0) {
                while (k % prime == 0) {
                    k = k/prime;
                    kcount++;
                }
            }
            ll p = prime, ncount = 0;
            while (p <= n) {
                ncount += (n/p);
                p *= prime;
            }
            if (kcount != 0)
                x = min(x, ncount/kcount);
        }
        if (k > 1) {
            ll kcount = 0, ncount = 0, prime = k, p = k;
            while (k > 1) {
                k = k/k;
                kcount++;
            }
            while (p <= n) {
                ncount += (n/p);
                p *= prime;
            }
            if (kcount != 0)
                x = min(x, ncount/kcount);
        }
        if (x == LLONG_MAX) {
            x = 0;
        }
        cout << x << endl;
    }
    return 0;
}
