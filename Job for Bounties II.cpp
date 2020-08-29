#include<bits/stdc++.h>
#define ll long long int
using namespace std;

class info {
public:
    ll rew, dur, deadl;
};
bool mycompare(info a, info b) {
    return a.deadl < b.deadl;
}

ll dp[101][1001];
ll ans(info p[], ll n, ll t, ll i = 0, ll c = 0) {
    if (i == n)
        return 0;
    if (dp[i][c] != -1)
        return dp[i][c];
    ll taken = 0, notTaken = 0;
    if(c + p[i].dur <= t and c + p[i].dur <= p[i].deadl)
        taken = p[i].rew + ans(p, n, t, i + 1, c + p[i].dur);
    notTaken = ans(p, n, t, i + 1, c);
    return dp[i][c] = max(taken, notTaken);
}

main() {
    ll t, n;
    cin >> t >> n;
    info p[n];
    for (ll i = 0; i < n; i++)
        cin >> p[i].rew;
    for (ll i = 0; i < n; i++)
        cin >> p[i].dur;
    for (ll i = 0; i < n; i++)
        cin >> p[i].deadl;
    sort(p, p + n, mycompare);
    memset(dp, -1, sizeof(dp));
    cout << ans(p, n, t, 0, 0);
}
