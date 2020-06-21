#include<bits/stdc++.h>
using namespace std;

int main(){
	char ch;
	cin >> ch;
	if(ch >= 'a' && ch <= 'z')
		cout << "L";
	else if(ch >= 'A' && ch <= 'Z')
		cout << "U";
	else
		cout << "I";
}
