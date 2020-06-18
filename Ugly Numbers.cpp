#include <bits/stdc++.h>
using namespace std;
long long int ugly(long long int n)
{
    long long int *arr=new long long int[n+1];
    arr[0]=1;
    long long int a2=0,b3=0,c5=0;
    long long int n2=2;
      long long int n3=3;
        long long int n5=5;
        long long int next=1;
     for(long long int i=1;i<n;i++)
     {
         next=min(n2,min(n3,n5));
         arr[i]=next;
         

         if(next==n2)
         {
             a2+=1;
             n2=arr[a2]*2;
         }
          if(next==n3)
         {
             b3+=1;
             n3=arr[b3]*3;
         }
         if(next==n5)
         {
             c5+=1;
             n5=arr[c5]*5;
         }
     }   
     delete []arr;
     return next;
}
int main() {
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        cout<<ugly(n)<<endl;

    }
    return 0;
}
