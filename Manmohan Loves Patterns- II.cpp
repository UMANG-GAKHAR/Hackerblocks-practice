#include <iostream>
using namespace std;
int main()
{
    int i, j,x = -1;
    int n;
    cin >> n;
    // Loop for each row
    for (i = 1; i <= n; i++)
    {
        if (x < 1)
        {
            for (j = 1; j <= i; j++)
                cout << "1";
        }
        else
        {
           for (j = 1; j <= i; j++)
           {
               if(j==1 || j==i)     
                cout << i-1;        // for 1st and last element of a row
               else
                cout << "0";        // for in between elements of a row
           }
        }
        cout << endl;
        x++;
    }
    return 0;
}
