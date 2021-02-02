#include <bits/stdc++.h>
#define nn 100100
#define ll long long int
using namespace std; 
ll a[nn];
 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        ll mx=0,mn=0;
        sort(a,a+n);
        for(int i=0;i<n/2;i++)
        {
            mx+=(a[i+n/2]-a[i]);
            mn+=(a[2*i+1]-a[2*i]);
        }
        cout<<mn<<" "<<mx<<endl;
    }
    return 0;
}
