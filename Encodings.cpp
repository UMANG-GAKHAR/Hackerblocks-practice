#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cassert>
#include <string>
#include <set>
#include <map>
#include <random>
#include <bitset>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using ld = long double;

const int MOD = 1e9 + 7, N = 100004;
ll ps[101];
ll pw[N], lv[N], rv[N], a[N];

ll f(string s) {
     int n = s.size() + 1;
     rep(i, n) {
          a[i] = (i == 0 ? 0 : s[i - 1] - '0');
          lv[i + 1] = (lv[i] * 10 + a[i]) % MOD;
     }
     rv[n] = 0;
     for (int i = n - 1; i >= 0; i--)
          rv[i] = (rv[i + 1] + a[i] * pw[n - 1 - i]) % MOD;
     ll ans = 0;
     for (int i = 1; i < n; i++) {
          ll x = a[i - 1] * 10 + a[i], ca = 0;
          ca = lv[i - 1] * pw[n - 1 - i] % MOD * ps[100] % MOD;
          ca = (ca + ps[x] * pw[n - 1 - i]) % MOD;
          if (a[i - 1] != a[i])
               ca = (ca + a[i] * (rv[i + 1] + 1)) % MOD;
          ans = (ans + ca * pw[n - 1 - i]) % MOD;

     }
     return ans;
}

int main() {
#ifndef ONLINE_JUDGE
     freopen("input3.txt",  "r",  stdin);
     freopen("output3.txt", "w", stdout);
#endif
     ios_base::sync_with_stdio(0); cin.tie(0);
     pw[0] = 1;
     rep(i, N - 1)
     pw[i + 1] = pw[i] * 10 % MOD;
     rep(i, 100)
     ps[i + 1] = ps[i] + (i / 10 != i % 10 ? i % 10 : 0);
     int t, nl, nr;
     cin >> t;
     string sl, sr;
     rep(z, t) {
          cin >> nl >> sl >> nr >> sr;
          for (int i = nl - 1; i >= 0; i--) {
               if (sl[i] == '0')
                    sl[i] = '9';
               else {
                    --sl[i];
                    break;
               }
          }
          cout << (f(sr) - f(sl) + MOD) % MOD << '\n';
     }
}
