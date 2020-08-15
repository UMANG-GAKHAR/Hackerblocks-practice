#include <iostream>
#include <algorithm>
using namespace std;
int dp[2001][2001][6];
int klcs(int a[],int i,int b[],int j,int k){
	if(i==-1 or j==-1)
		return 0;
	
	if(dp[i][j][k] != -1){
		return dp[i][j][k];
	}



	if(a[i] == b[j]){
		return 1+klcs(a,i-1,b,j-1,k);
	}

	int op1=klcs(a,i-1,b,j,k);
	int op2=klcs(a,i,b,j-1,k);
	int op3 = -1;
    if(k>0){
        op3=1+klcs(a,i-1,b,j-1,k-1);
    }
	return dp[i][j][k]=max(op1,max(op2,op3));
}
int main(){
	int n,m,k;
	memset(dp,-1,sizeof dp);
	cin>>n>>m>>k;
	int a[n],b[m];
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	for(int i=0;i<m;++i){
		cin>>b[i];
	}
	cout<<klcs(a,n-1,b,m-1,k);
}
