#include<iostream>
using namespace std;
int fact(int n)
{
    if (n == 0 || n == 1)
    {   return 1;
    }
    return n * fact(n - 1);
}
int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}
int main() {
    long int n;
    cin >> n;
    if(n==1){
        cout<<n;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }
        for (int k = 0; k <= i; k++)
        {
            cout << " " << nCr(i, k);
        }
        cout << endl;
    }
    return 0;
}
