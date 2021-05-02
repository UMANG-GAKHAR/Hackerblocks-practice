#include<bits/stdc++.h>
using namespace std;
int main(){
int n,i;
cin>>n;
int arr[n];
for(i=0;i<n;i++)cin>>arr[i];
int brr[n];
stack<int> stk;
for(i=n-1;i>=0;i--)
{
   while(!stk.empty() && (arr[stk.top()] > arr[i]) )
       stk.pop();
       if(stk.empty())
        brr[i]=-1;
       else
       {
           brr[i]=stk.top();
       }
       stk.push(i);
}
for(i=n-1;i>=0;i--)
{
   while(!stk.empty() && !(arr[stk.top()] > arr[i]))
       stk.pop();
       if(stk.empty())
        brr[i]=-1;
       else
       {
           brr[i]=stk.top();
       }
       stk.push(i);
}
for(i=0;i<n;i++)
{   if(brr[i]!=-1)
    cout<<arr[brr[i]]<<" ";
    else
        cout<<"-1 ";
}
}
