#include <iostream>
using namespace std;
int main() {
    long long int n;
    cin >> n;
    long long int i,j,k;
    long long int arr[n];

    //Input from the user
    for (i = 0; i < n; i++)
        cin >> arr[i];

    //Two for loof which compare the element of arrays.
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n-1;j++)
        {
            if (arr[j] > arr[j+1])
            {
                k = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = k;
            }
        }
    }

    //Print required Output
    for (i = 0; i < n; i++)
        cout << arr[i] << endl;

    return 0;
}
