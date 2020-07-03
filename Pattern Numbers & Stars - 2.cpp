#include <iostream>
using namespace std;
int main ()
{
    int i, j, n;
    cin >> n;
    //loop for each row
    for (i = 1; i <= n; i++)
    {
       // work for numbers
        for (j = 1; j <= i; j++)
            cout << j;

       // work for stars
        for (j = 1; j <= n - i; j++)
            cout << "*";
        cout << endl;
    }
    return 0;
}
