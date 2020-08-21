#include<iostream>
#include<unordered_map>
using namespace std;
int main() 
{
    unordered_map<long int,long int> m;
    long int n,k;
    cin>>n>>k;
    long int arr[n];
    for(long int i=0;i<n;i++)
       cin>>arr[i];
    for(long int i=0;i<n;i++)
      m[arr[i]] = i;
    for(int i=0;i<n && k ;i++)
    {
        if(arr[i]==n-i)
        {
            continue;
        }
        int temp=m[n-i];
        m[arr[i]]=m[n-i];
        m[n-i]=i;
        swap(arr[temp],arr[i]);
        --k;
    }
    for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
	return 0;
}
