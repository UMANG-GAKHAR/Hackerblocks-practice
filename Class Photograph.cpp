#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false); cin.tie(nullptr); cin.tie(nullptr);
#define ll long long
#define mod 1000000007
#define inf INT_MAX
using namespace std;

int cp(vector<vector<vector<vector<int>>>>& dp, int b, int g, int ab, int ag, int ib = 0, int ig = 0) {

    if (!b and !g)
        return 1;

    int boys, girls;
    boys = girls = 0;

    if (dp[b][g][ib][ig] != -1)
        return (dp[b][g][ib][ig]);

    if (b and ib < ab)
        boys = cp(dp, b - 1, g, ab, ag, ib + 1, 0);
    if (g and ig < ag)
        girls = cp(dp, b, g - 1, ab, ag, 0, ig + 1);

    return dp[b][g][ib][ig] = (boys % mod + girls % mod) % mod;
}

int main() {
    fast
    int b, g, ab, ag;
    cin >> b >> g >> ab >> ag;
    vector<vector<vector<vector<int>>>> dp(b + 1, vector<vector<vector<int>>>(g + 1 , vector<vector<int>>(ab + 1, vector<int>(ag + 1, -1))));
    cout << cp(dp, b, g, ab, ag) << endl;
}
