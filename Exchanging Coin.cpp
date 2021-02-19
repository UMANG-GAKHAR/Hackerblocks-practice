#include<iostream>
#include<unordered_map>
#define ll long long
using namespace std;
ll int solve(ll int n,unordered_map<ll int,ll int>&dp)
{
	if(dp.count(n))
		return dp[n];
	if(n<12)
	{
		dp[n]=n;
		return dp[n];
	}

		dp[n]=max(n,solve(n/2,dp)+solve(n/3,dp)+solve(n/4,dp));
		return dp[n];
	
}
int main()
{
	int n;
	cin>>n;
	unordered_map<ll int,ll int>dp;
	cout<<solve(n,dp);
}
