#include<iostream>
#include<stack>
using namespace std;

int main() {
	int n;
	cin>>n;
	long arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	stack<int> s;
	s.push(0);
	long area=0;
	for(int i=1;i<n;i++){
		//Current element is smaller or equal:
		while(!s.empty() && arr[s.top()]>=arr[i]){
			//Pop element from stack:
			int t=s.top();
			s.pop();
			//After poping:
			//a. Stack becomes empty: all elements on it's left are larger to it:
			if(s.empty()){
				area=max(area,arr[t]*i);
			}
			//b. Stack is not empty: current top of stack is smaller to it:
			else{
				area=max(area,arr[t]*(i-s.top()-1));
			}
		}
		//Push index of current:
		s.push(i);
	}


	//If stack still contains some element: When the last element was larger than the top of stack:
	while(!s.empty()){
		//Pop element from stack:
			int t=s.top();
			s.pop();
			//After poping:
			//a. Stack becomes empty: all elements on it's left are larger to it:
			if(s.empty()){
				//changes
				area=max(area,arr[t]*n);
			}
			//b. Stack is not empty: current top of stack is smaller to it:
			else{
				//Changes:
				area=max(area,arr[t]*(n-s.top()-1));
			}
	}

	cout<<area;
	return 0;
}
