#include<bits/stdc++.h>
#define mod 1000000007
#define pp pair<ll,ll>
#define mp make_pair
#define ll long long
#define pb push_back
#define ff first
#define ss second
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    string str;
    stack<int> stck;
    int dp[100010] = {0},ans=0;
    //dp[i] stores the length of longest valid substring if it teerminates at ith position

    cin>>str;
    for(int i=0;i<str.length();i++){
        if(str[i] == '(')
            stck.push(i);
        else if(!stck.empty()){
            dp[i] = i-stck.top()+1;//length of open and close bracket pair
            if(stck.top() > 0)
                dp[i] += dp[stck.top()-1];//add length of previous valid substrings
            ans = max(ans,dp[i]);//update ans if value of dp[i] is more than ans
            stck.pop();//pop '(' from stack
        }
    }
    cout<<ans;
    return 0;
}
