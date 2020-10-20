#include<iostream>
#define mod 1000000007
#define ll long long int
using namespace std;
ll ans[2100][2100];
ll na[10000];
ll nn,nm,ns,nt;
 
int main()
{
    cin>>nn>>nm>>ns;
    for(int i=0;i<nm;i++)
        cin>>na[i];
    ans[ns-1][0]=1;
    for(int j=0;j<nm;j++)
    {
        for(int i=0;i<nn;i++)
        {
            if(i+na[j]<nn) ans[i+na[j]][j+1]=(ans[i][j]+ans[i+na[j]][j+1])%mod;
            if(i-na[j]>=0) ans[i-na[j]][j+1]=(ans[i][j]+ans[i-na[j]][j+1])%mod;
        }
    }
    ll fans=0;
    for(int i=0;i<nn;i++)
    {
        fans+=ans[i][nm];
        fans%=mod;
    }
    cout<<fans<<endl;
    return 0;
}
