#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
map<char,ll int> m;
string s;
ll int dp[1003][1003];
ll int mini(ll int a,ll int b)
{
    if(a<b)
        return a;
    else
        return b;

}
ll int ans(ll int i,ll int l ,ll int ml) // l is length and ml is the maximum allowed length
{if(s[i]==0)// if i reached at end then i have successfully reached at end so return 1
return 1;
if(dp[i][l]!=-1)
    return dp[i][l];
ll int ans1=0;
if(i==0)
{ans1=(ans1%mod+ans(i+1,1,m[s[i]])%mod)%mod;
}    // starting with including first character in my expanding length
else
{
if(l==ml) // if i have covered maximum allowed length then i have no choice but to start from this character
ans1=(ans1%mod+ans(i+1,1,m[s[i]])%mod)%mod;
else   // else i have 2 choices either to start again from this character or include this character in my current expanding length
{ll int e=mini( ml,m[s[i]]);// because if i have a,b maximum upto which I can traverse can go is the minimum of these 2 values
ans1=(ans1%mod+ans(i+1,1,m[s[i]])%mod+ans(i+1,l+1,e)%mod)%mod;
}
}
return dp[i][l]=ans1;


}
int main()
{memset(dp,-1,sizeof dp);
ll int n;
cin>>n;
cin>>s;

char c='a';
for(ll int i=0;i<2;i++)
{ll int e;
cin>>e;
m[c+i]=e;
}
ll int d=ans(0,0,0);

cout<<d<<endl;
}
