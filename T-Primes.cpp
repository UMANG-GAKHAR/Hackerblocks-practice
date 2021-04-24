#include < bits/stdc++.h >
using namespace std;
 #define LIMIT 1000000
long long i, j;
long long primeflag[LIMIT];
void calculateprimeflag(){
    primeflag[0] = primeflag[1] = 1;
    for(i=2;iflag[i]==0){
            for(j=i*i;j<LIMIT;j+=i){
                primeflag[j] = 1;
            }
        }
    }
}
int checkperfectsquare(long long n){
    double sqrtn = sqrt(n);
    if(sqrtn == int(sqrtn)){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    calculateprimeflag();
    long long totalnumbers, n;
    cin>>totalnumbers;
    for(i=0;i<totalnumbers;i++){
        cin>>n;
        if (n==4){
            cout<<"YES"<perfectsquare(n)==1 && primeflag[int(sqrt(n))]==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
