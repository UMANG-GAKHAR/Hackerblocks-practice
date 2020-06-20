#include<iostream>
using namespace std;

int main() {
    int i, j;
    int n;
    cin >> n;
    //loop for each row
    for (i = 1; i <= n; i++)
    {

           for (j = 1; j <= i; j++)
           {
               if(j==1 || j==i)
                cout << i<<"    ";               // for 1st and last element
               else
                cout << "0"<<"  ";             // for in between elements
           }

        cout << endl;

    }
    return 0;
}
