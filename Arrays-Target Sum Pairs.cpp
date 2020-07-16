#include<bits/stdc++.h>
using namespace std;

int main() 
{
	int n;
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++)
    cin>>a[i];

    int target;
    cin>>target;

	sort(a,a+n);          //sort the array

    int l=0, r=n-1;        // l point to starting element,  r points to last element

    while(l<r)            // traverse whole array
    {
       if(a[l]+a[r]==target)       // pair found
       {
           cout<< a[l] << " and " << a[r]<< endl;
           l++;
           r--;
       }
       else if((a[l] + a[r]) < target)  //pair sum < target  ////////////////////////////////////////////////////////////////////////////////////
       l++;
       else 
	   r--;
    }
}
