#include <iostream>
using namespace std;
int main ()
{
    long long int n;    // long long int to capture big value of n
    cin >> n;

    long long int sum = 0, pow = 1, t;
    do
    {
        t = n%10;        // Extracting the digit
        if (t == 0)      
            t = 5;       // If digit is zero then make t = 5
        sum = sum + t*pow;   // Prepare the answer
        pow = pow*10;    // Update the power 
        n = n/10;       // Update the number
    } while (n != 0);
    cout << sum;       // print the desired answer
    return 0;
}
