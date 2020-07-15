#include<bits/stdc++.h>
using namespace std;

bool comp(string a,string b){
if (a.size()<=b.size()&& b.substr(0,a.size())==a) return false;
else if (b.size()<=a.size() && a.substr(0,b.size())==b) return true;
else return a<b;

}
int main() {
int t;
cin>>t;
string full[1001];
for (int i = 0;i<t;i++){

	cin>>full[i];
}

for (int i = 0;i<t;i++){
	for (int j = i;j<t;j++){
		if (!comp(full[i],full[j])){
			full[i].swap(full[j]);
			
		}
	}
}

for (int i = 0;i<t;i++){
	cout<<full[i]<<endl;
}
return 0;
}
