#include<bits/stdc++.h>
using namespace std;
int dp[201][201][201];
int lcs3(string a,string b,string c,int l1,int l2,int l3){
    for(int i=0;i<=l1;i++){
        for(int j=0;j<=l2;j++){
            for(int k=0;k<=l3;k++){
                if(i==0 || j==0 || k==0){
                    dp[i][j][k]=0;
                }
                else if(a[i-1]==b[j-1] && a[i-1]==c[k-1]){
                    dp[i][j][k]=1+dp[i-1][j-1][k-1];
                }
                else{
                    dp[i][j][k]=max({dp[i][j][k-1],dp[i-1][j][k],dp[i][j-1][k]});
                }
            }
        }
    }
    return dp[l1][l2][l3];
}
int main(){
    string a,b,c;
    cin>>a>>b>>c;
    int l1,l2,l3;
    l1=a.length();
    l2=b.length();
    l3=c.length();
    int s=lcs3(a,b,c,l1,l2,l3);
    cout<<s;
}
