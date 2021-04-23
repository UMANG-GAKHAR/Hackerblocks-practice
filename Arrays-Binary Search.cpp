#include <stdio.h>
#include<iostream>
using namespace std;
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r-l)/2;
        // Check if x is present at mid
        if (arr[m] == x)
            return m;

        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;

        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
    return -1;
}
int main(void)
{
    int n;
    cin >> n;
    int i;
    int arr[n];
    for (i = 0; i < n; i++)
        cin >> arr[i];
    int num;
    cin >> num;
    int result = binarySearch(arr, 0, n-1, num);
    (result == -1)? printf("%d", -1)
            : printf("%d",result);
    return 0;
}
