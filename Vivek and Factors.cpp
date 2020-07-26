#include <bits/stdc++.h>
using namespace std;
    int a[100000000];
    int b[100000000]={0};
void sumofFactors(int n) 
{ 
    int m=n;
    int res = 1; 
    for (int i = 2; i <= sqrt(n); i++) 
    { 
        int curr_sum = 1; 
        int curr_term = 1; 
        while (n % i == 0) { 
            n = n / i; 
  
            curr_term *= i; 
            curr_sum += curr_term; 
        } 
  
        res *= curr_sum; 
    } 
    if (n >= 2) 
        res *= (1 + n); 
  
    b[res]=res;
    a[res]= m;
} 
int main() {
    b[1]=1;a[1]=1;
    for(int i=2;i<=100000;i++){
        sumofFactors(i);
}
    int x;cin>>x;
    while(x!=0){
        if(b[x]!=0){
            cout<<a[x]<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
        cin>>x;
    }
}
