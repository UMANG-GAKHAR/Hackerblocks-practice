#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
long long int dp[1001][1001];
long long int minmoney(int a[],int n,int w){
	if(w==0)
		return 0;
	if(n==0)
		return INT_MAX;
	if(dp[n][w] != -1)
		return dp[n][w];

	long long int op1 = minmoney(a,n-1,w);
	if(w < n or a[n-1]==-1)
		return op1;

	long long int op2=a[n-1]+minmoney(a,n,w-n);
	return dp[n][w]=min(op1,op2);
		
}
int main(){
	int n,w;
	cin>>n>>w;
	memset(dp,-1,sizeof(dp));
	int a[w];
	for(int i=0;i<w;++i)
		cin>>a[i];
	cout<<minmoney(a,w,w);
	return 0;
}
