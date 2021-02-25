#include<bits/stdc++.h>
using namespace std;
int main() {
	int t,n;
	cin>>t;
	while(t--){
	cin>>n;
        int arr[n];
        int inc[n];
        int dec[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		// intiallising 1st of inc with 1 it will be inc.
		inc[0]=1;dec[n-1]=1;
		// finding range till its inc.
		for(int i=1;i<n;i++){
			if(arr[i]>=arr[i-1]){
				inc[i]=1+inc[i-1];
			}
            else
                inc[i]=1;  //////////////////////////////////////////////////////////////////////////////////////////////////
		}
		// finding range till its dec.
		for(int i=n-2;i>=0;i--){
			if(arr[i]>=arr[i+1]){
				dec[i]=1+dec[i+1];
			}
            else
                dec[i]=1;  //////////////////////////////////////////////////////////////////////////////////////////////////////////////
		}  
		
		int maxc=inc[0]+dec[0]-1;
		for(int i=1;i<n;i++){
			maxc=max(inc[i]+dec[i]-1,maxc);
		}
		cout<<maxc<<"\n";
	}
	return 0;
}
