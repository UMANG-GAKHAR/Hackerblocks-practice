#include <iostream>
#include <cmath>
using namespace std;
int main ()
{
    float p, a;
    int n;
    cin >> p;
    if(p!=1)
    {
//Finding Probability for a
    a = log(1/(1-p));
//Minimum number of people required
    n = sqrt (2*365*a);
    }
//If given probability is one
    else
    {
        n = 365;
    }
    cout << n+1;
    return 0;
}
