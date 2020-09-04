#include<bits/stdc++.h>
using namespace std;
#define MAXN 1010
#define MAXW 1010
double DP[MAXN][MAXW];
int main(){
	int t;
	cin>>t;
	while(t--){
		int X,Y,N,W,P1,P2;
		cin>>X>>Y>>N>>W>>P1>>P2;
		for(int i=0;i<=N;i++){
			for(int j=0;j<=W;j++){
				DP[i][j]=0;
			}
		}
		double p1 = 0.01 * P1;
		double p2 = 0.01 * P2;
		for (int i=0;i<=N;i++) 
      		DP[i][0] = 1; 
    	for (int i=1;i<=W;i++) 
      		DP[0][i] = 0; 
    	for (int i=1;i<=N;i++){ 
      		for (int j=1;j<=W;j++) { 
        		DP[i][j] = max(p1*DP[i-1][max(j-X,0)] + (1-p1)*DP[i-1][max(j,0)], p2*DP[i-1][max(j-Y,0)] + (1-p2)*DP[i-1][max(j,0)]); 
      		} 
      	}
      	printf("%.6f\n",DP[N][W]*100);
	}
}
