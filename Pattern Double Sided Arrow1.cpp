#include <iostream>
using namespace std;
int main() {
   int n;
   cin>>n;
   for(int i=1;i<=n/2+1;i++){
       if(i==1){
           for(int s=1;s<=n-2*i+1;s++){
               cout<<" "<<" ";
           }
           cout<<"1";
       }
       else{
           for(int s=1; s<=n-2*i+1;s++){
               cout<<" "<<" ";
           }
           for(int j=i;j>=1;j--){
               cout<<j<<" ";
           }
           for(int s=1;s<=2*i-3;s++){
                cout<<" "<<" ";
           }
           for(int j=1;j<=i;j++){
               cout<<j<<" ";
           }
       }
       cout<<endl;
   }
   for(int i=1;i<=n/2;i++){
       int val=n/2+1-i;
       if(i==n/2){
           for(int s=1;s<=2*i;s++){
               cout<<" "<<" ";
           }
           cout<<"1";

       }
       else{
             for(int s=1;s<=2*i;s++){
                cout<<" "<<" ";
            }
            for(int j=1;j<=n/2+1-i;j++){
                 cout<<val<<" ";
                   val--;
            }
			
       //THIS PART OF SPACES  IS WHAT I M DOING WRONG PLEASE CORRECT THIS ONE !
			
            for(int s=1;s<n-2*i-1;s++){
                cout<<" "<<" ";
            }
              val++;
             for(int j=1;j<=n/2+1-i;j++){
                 cout<<val<<" ";
                 val++;
            }
       }
             cout<<endl;
   }
   return 0; 
}
