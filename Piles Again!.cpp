#include <bits/stdc++.h>
using namespace std;
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define Mod 1000000007
typedef long long int lli;
using namespace std;
int main()
{
    lli t;
    cin>>t;
    while(t--)
    {
        lli n;
        cin>>n;
        lli ans=0;
        lli i;
        for(int i=0;i<n;i++)
        {
            lli x;
            cin>>x;
            if(i!=0)
            {
             if(x%2!=0)
             {
                ans=ans xor i;
             }
            }
        }
        if(ans==0)
            cout<<"Second";
        else
            cout<<"First";
        cout<<"\n";
    }
}
