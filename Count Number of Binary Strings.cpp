#include <iostream>
using namespace std;
#include <iostream> 
using namespace std; 
  
long long countStrings(int n) 
{ 
    long long a[n], b[n]; 
    a[0] = b[0] = 1; 
    for (int i = 1; i < n; i++) 
    { 
        a[i] = a[i-1] + b[i-1]; 
        b[i] = a[i-1]; 
    } 
    return a[n-1] + b[n-1]; 
} 

int main() 
{ int t;
   int n;
   cin>>t;
   while(t--)
   {
	   cin>>n;
	    cout << countStrings(n) << endl;
	   
   }
   
    
    return 0; 
}
