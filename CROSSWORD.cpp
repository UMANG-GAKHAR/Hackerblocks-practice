#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define mp make_pair
#define fs first
#define ss second
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);
using namespace std;
unordered_map<string,ll> dict;
void solve(char a[][5],int i,int j,int m,string ans)
{  //Base Case
    if(i<0 || j<0 || i==m || j==m)
        return;
    ans+=a[i][j];
    if(dict[ans]!=0)
    {
        cout<<ans<<" ";
        dict[ans]=0;
    }
    string temp=ans;
    int i1=i-1,j1=j-1;
    while(i1>=0 && j1>=0)
    {
        temp+=a[i1][j1];
        if(dict[temp]!=0)
        {
            cout<<temp<<" ";
            dict[temp]=0;
        }
        i1--;
        j1--;
    }
    temp=ans;
    i1=i-1;j1=j;
    while(i1>=0 && j1>=0)
    {
        temp+=a[i1][j1];
        if(dict[temp]!=0)
        {
            cout<<temp<<" ";
            dict[temp]=0;
        }
        i1--;
    }
    temp=ans;
    i1=i-1;j1=j+1;
    while(i1>=0 && j1<m)
    {
        temp+=a[i1][j1];
        if(dict[temp]!=0)
        {
            cout<<temp<<" ";
            dict[temp]=0;
        }
        i1--;
        j1++;
    }
    temp=ans;
    i1=i;j1=j-1;
    while(i1>=0 && j1>=0)
    {
        temp+=a[i1][j1];
        if(dict[temp]!=0)
        {
            cout<<temp<<" ";
            dict[temp]=0;
        }
        j1--;
    }
    temp=ans;
    i1=i;j1=j+1;
    while(i1>=0 && j1<m)
    {
        temp+=a[i1][j1];
        if(dict[temp]!=0)
        {
            cout<<temp<<" ";
            dict[temp]=0;
        }
        j1++;
    }
    temp=ans;
    i1=i+1;j1=j-1;
    while(i1<m && j1>=0)
    {
        temp+=a[i1][j1];
        if(dict[temp]!=0)
        {
            cout<<temp<<" ";
            dict[temp]=0;
        }
        i1++;
        j1--;
    }
    temp=ans;
    i1=i+1;j1=j;
    while(i1<m && j1>=0)
    {
        temp+=a[i1][j1];
        if(dict[temp]!=0)
        {
            cout<<temp<<" ";
            dict[temp]=0;
        }
        i1++;
    }
    temp=ans;
    i1=i+1;j1=j+1;
    while(i1<m && j1<m)
    {
        temp+=a[i1][j1];
        if(dict[temp]!=0)
        {
            cout<<temp<<" ";
            dict[temp]=0;
        }
        i1++;
        j1++;
    }
    return;
}
int main()
{
    dict.clear();
    fast;
    ll n,m;
    string word;
    cin>>n;
    for(ll i=0;i<n;i++)
    {
        cin>>word;
        dict[word]=1;
    }
    cin>>m;
    char a[5][5];
    for(ll i=0;i<m;i++)
    {
        for(ll j=0;j<m;j++)
            cin>>a[i][j];
    }
    for(ll i=0;i<m;i++)
    {
        for(ll j=0;j<m;j++)
        {
            string ans="";
            solve(a,i,j,m,ans);
        }
    }
    return 0;
}
