#include <bits/stdc++.h>

using namespace std;

long long n;
long long arr [100000 + 1];
long long dp [100000 + 1][4 + 1][16 + 1];
long long sett [100000 + 1];

long long rec (long long index, long long order, long long msk){

    if(index == n){                                     // base case

        if(order == 3 && msk) return 1;                 // valid case
        return 0;                                       // invalid case
    }

    long long &st = dp[index][order][msk];
    if(st != -1) return st;

    long long ans = rec(index + 1, order, msk);                             // ignore this number
    if(order <= 2) ans += rec(index + 1, order + 1, msk &  sett[index] );   // take this number in the triplet if there is 2 or less in the triplet

    return st = ans;
}


int main()
{
    ios::sync_with_stdio(false);cin.tie(0);         // decrease the time of cin, cout

    memset(dp, -1, sizeof dp);                      // set dp array as unvisted states

    cin >>      n          ;

    for(int i = 0; i < n; i++){

        cin >> arr[i];

        while(arr[i] != 0){                         // set the prime digits in ebery number

            int digit = arr[i] % 10;                // extract a digit by digit from the number

            if(digit == 2) sett[i] |= (1 << 0);
            else if (digit == 3) sett[i] |= (1 << 1);
            else if (digit == 5) sett[i] |= (1 << 2);
            else if (digit == 7) sett[i] |= (1 << 3);

            arr[i] /= 10;
        }
    }

    cout << rec(0 , 0, 15) << "\n";     // 15 is the mask value (1111) for setting (2,3,5,7) as ones.

    return 0;
}
