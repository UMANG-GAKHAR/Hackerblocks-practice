

#include <bits/stdc++.h>
using namespace std;



bool canplace(int arr[][9], int n, int i, int j, int num)
{
    // check col and rows and boxes.
    // row
    for (int k = 0; k < n; k++)
    {
        if (arr[i][k] == num|| arr[k][j]==num)
        {
            return false;
        }
    }
   
    // box.
    int no = sqrt(n);
    int startrow = (i/no)*no;
    int startcol = (j/no)*no;
    for (int k = startrow; k < startrow+no; k++)
    {
        for (int l = startcol; l < startcol+no; l++)
        {
            if (arr[k][l] == num)
            {
                return false;
            }
        }
    }
    return true;
}
bool sudoku(int arr[][9], int n, int i, int j)
{
   //base case
	if(i==n){
		//print the matrix
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				cout<<arr[i][j]<<" ";
			}
			cout<<endl;
		}
		return true;
	}
	//case for row end
	if(j==n){
		return sudoku(arr,n,i+1,0);
	}
	//skip the pre filled cells
	if(arr[i][j]!=0){
		return sudoku(arr,n,i,j+1);
	}
    for (int num = 1; num <= 9; num++)
    {
        if (canplace(arr, n, i, j, num))
        {
            arr[i][j] = num;
            bool cansolve = sudoku(arr, n, i, j + 1);
            if (cansolve)
            {
                return true;
            }
        }
    }
    arr[i][j] = 0;

    return false;
}

int main()
{
    int n;
    cin >> n;
    int arr[n][9];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> arr[i][j];
        }
    }

    sudoku(arr, 9, 0, 0);
    return 0;
}
