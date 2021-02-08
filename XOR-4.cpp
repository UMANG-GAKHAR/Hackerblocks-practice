#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
const int limit    =   64*2+10;

int main(){
//     freopen("input4.txt","r",stdin);
//    freopen("output4.txt","w",stdout);

    int n;

    unsigned long long a[limit];

    cin >> n;

    if (n>=limit){//if n > 130, one can definitely find four numbers in the sequence such that their xor is 0

        puts("YES");

        return 0;
    }
     //otherwise, search through the array for all possibles quadruples
    for (int i=0;i<n;++i)

        cin >> a[i];

    for (int i=0;i<n;++i)

        for (int j=i+1;j<n;++j)

            for (int k=j+1;k<n;++k)

                for (int l=k+1;l<n;++l)

                if ((a[i]^a[j]^a[k]^a[l])==0){
                    puts("YES");
                    return 0;
                }
    puts("NO");
    return 0;
} 
