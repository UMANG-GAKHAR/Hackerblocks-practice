#include <iostream>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    int arr[n][m];
   
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    // code
    int top = 0, bottom = n - 1, left = 0, right = m - 1;

    while (top <= bottom && left <= right)
    {
        for (int i = top; i <= bottom; i++)
        {
            cout << arr[i][left] << ", ";
        }
        left++;
        for (int i = left; i <= right; i++)
        {
            cout << arr[bottom][i] << ", ";
        }
        bottom--;
        if (bottom > top)
        {
            for (int i = bottom; i >= top; i--)
            {
                cout << arr[i][right] << ", ";
            }
            right--;
        }

        if (right > left)
        {
            for (int i = right; i >= left; i--)
            {
                cout << arr[top][i] << ", ";
            }
            top++;
        }
    }
    cout<<"END";
}
