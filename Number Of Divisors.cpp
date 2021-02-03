#include<iostream>
#include<math.h>
using namespace std;
bool isPrime(long long int num){
    if(num==2){
        return true;
    }
    if(num<2||(num&1)==0){
        return false;
    }
    long long int sqrtNum = sqrt(num);
    for (long long int i = 3; i <= sqrtNum; i+=2) {
        if(num%i==0){
            return false;
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        long long int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long int freqOfPrimeFact[1000001] = {0};
        for (int i = 0; i < n; i++) {
            long long int temp = a[i];

            if(isPrime(a[i])){
                freqOfPrimeFact[a[i]]++;
                continue;
            }

            while((temp&1)==0){
                freqOfPrimeFact[2]++;
                temp/=2;
            }

            if(isPrime(a[i])){
                freqOfPrimeFact[a[i]]++;
                continue;
            }

            for (long long int j = 3; j <= a[i]; j+=2) {
                if(temp==0){
                    break;
                }
                while((temp%j)==0){
                    freqOfPrimeFact[j]++;
                    temp/=j;
                }
            }
        }
        int count=1;
        for (long long int i = 2; i < 1000001; i++) {
           if(freqOfPrimeFact[i]){
                count*=(freqOfPrimeFact[i]+1);    
           }
        }
        cout << count <<endl;
    }
    return 0;
}
