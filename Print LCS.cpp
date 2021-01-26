#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define f first
#define int long long
#define pb push_back

int dp[3005][3005];
string s, t;


int cal_seq(int index_1, int index_2) {

       if (index_1 <= 0 || index_2 <= 0 )     return 0;

       if (dp[index_1][index_2] != -1)       return dp[index_1][index_2];

       if (s[index_1 - 1] == t[index_2 - 1])
              dp[index_1][index_2] = max(dp[index_1][index_2], 1 + cal_seq(index_1 - 1, index_2 - 1));

       else dp[index_1][index_2] = max(cal_seq(index_1 - 1 , index_2), cal_seq(index_1, index_2 - 1));
       return dp[index_1][index_2];

}
void solve() {
       cin >> s >> t;
       memset(dp, -1, sizeof(dp));
       cal_seq(s.length(), t.length());
       vector<char> ans;
       int index_1 = s.length(), index_2 = t.length();

       while (index_1 >= 0 && index_2 >= 0) {
              if (index_1 == 0 || index_2 == 0)  break;
              if (s[index_1 - 1] == t[index_2 - 1])  ans.pb(s[index_1 - 1]), index_1--, index_2--;
              else if (dp[index_1 - 1][index_2] >= dp[index_1][index_2 - 1])      index_1--;
              else index_2--;
       }
       reverse(ans.begin(), ans.end());
       for (auto i : ans)      cout << i;
}
signed main()
{
       solve();
}
