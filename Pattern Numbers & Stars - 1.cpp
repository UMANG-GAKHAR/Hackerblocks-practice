#include <iostream>
using namespace std;
int main ()
{
    int i, j, n;
    cin >> n;

    // loop for each row
    for (i = 1; i <= n; i++)
    {
       // work for numbers 
        for (j = 1; j <= n+1-i; j++)
            cout << j << " ";

       // work for stars
        for (j = 1; j <= 2*(i-1) - 1; j++)
            cout << "* ";
        cout << endl;
    }
    return 0;
}
