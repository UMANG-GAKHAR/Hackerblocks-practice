#include<iostream>
using namespace std;
void print(int *arr, int n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
}
void sortLinearTime(int *arr, int l, int mid, int h) {
	while (mid <= h) {
		if (arr[mid] == 0) {
			swap(arr[l], arr[mid]);
			l++;
			mid++;
		}
		else if (arr[mid] == 1) {
			mid++;
		}
		else {
			swap(arr[mid], arr[h]);
			h--;
		}
	}
}
int main() {
	
	int n;
	cin >> n;
    int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int l = 0;
	int mid = 0;
	int h = n - 1;
	sortLinearTime(arr, l, mid, h);
	print(arr, n);
	return 0;
}
