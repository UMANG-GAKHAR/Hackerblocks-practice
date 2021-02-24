#include <bits/stdc++.h>
using namespace std;
int binary_searchh(int *a,int no,int s,int e)
{
    while(s<=e)
    {
        int mid=(s+e)/2;
        if(no==a[mid])
        {
            return mid;
        }
        else if(no>a[mid])
        {
            s=mid+1;
        }
        else
        {
            e=mid-1;
        }
    }
    return -1;
}
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        int q;
        cin>>q;
        while(q--)
        {
            int no;
            cin>>no;
            if(binary_searchh(a,no,0,n-1)!=-1)
            {
                cout<<"Yes"<<endl;
            }
            else
            {
                cout<<"No"<<endl;
            }
        }
    }
}
