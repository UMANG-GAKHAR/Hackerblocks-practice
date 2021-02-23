#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int mod = 1000000000 + 7;
int count( int S[], int m, int n ) 
{ 
    int table[n+1]; 

    // Initialize all table values as 0 
    memset(table, 0, sizeof(table)); 

    // Base case (If given value is 0) 
    table[0] = 1; 

    // Pick all coins one by one and update the table[] values 
    // after the index greater than or equal to the value of the 
    // picked coin 
    for(int i=0; i<m; i++) 
        for(int j=S[i]; j<=n; j++) 
            table[j] += table[j-S[i]],table[j]%=mod; 
    return table[n]; 
}  
void solve(){
    int m;
    cin>>m;
    int a[m];
    for(int i=0;i<m;i++)cin>>a[i];
    int n;
    cin>>n;
    cout<<count(a,m,n)<<endl;
}
signed main() {
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
    }
