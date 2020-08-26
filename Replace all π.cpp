#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;
		for(int i = 0; i < s.length(); i++){
			if(s[i] == 'p'){
				if(i+1 < s.length() && s[i+1] == 'i'){
					cout << "3.14";
					i += 1;
				}
				else
					cout << 'p';
			}
			else
				cout << s[i];
		}
		cout << endl;
	}
}
