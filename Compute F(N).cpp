#include <iostream>
using namespace std;
int main ()
{
    signed long long int i, n;
//Total number of test case
    cin >> n;
//Working for each test case
    for ( i = 0; i < n; i++)
    {
        signed long long int num;
        cin >> num;
//If given input is even 
        if (num%2 == 0)
            cout << num/2 <<endl;
//If given input is odd
        else if (num%2 == 1)
        {
            signed long long int t;
            t = (num-1)/2 - num;
            cout << t << endl;
        }
    }
    return 0;
}

