#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
class node {
public:
	char data;
	bool isTerminal;
	unordered_map<char,node*>childeren;
	node(char ch) {
		data = ch;
		isTerminal = false;
	}
};
class Tries
{
	node*root;
public:
	Tries(){
		root=new node('\0');
	}
	void AddWord(string str){
		node*temp=root;
		for(int i=0;str[i]!='\0';i++){
			char ch=str[i];
			if(temp->childeren.count(ch)){
				temp=temp->childeren[ch];
			}else{
				node*n=new node(ch);
				temp->childeren[ch]=n;
				temp=n;
			}
		}
		temp->isTerminal=true;
	}
	bool Search(string str){
		node*temp=root;
		for(int i=0;str[i]!='\0';i++){
			char ch=str[i];
			if(temp->childeren.count(ch)){
				temp=temp->childeren[ch];
			}
			else return false;
		}
		if(temp->isTerminal)return true;
		return false;
	}
	void PrintAll(node*temp,string out,vector<string>&ans){
		if(temp->isTerminal){
			ans.push_back(out);
		}

		for(auto it:temp->childeren){
			out.push_back(it.first);
			PrintAll(it.second,out,ans);
			out.pop_back();
		}
	}
	void Suggestion(string str){
		node*temp=root;
		string out="";
		for(int i=0;str[i]!='\0';i++){
			char ch=str[i];
			if(temp->childeren.count(str[i])){
				out.push_back(ch);
				temp=temp->childeren[ch];
			}
			else {
				cout<<"No suggestions"<<endl;
				AddWord(str);
				return;	
			}
		}
		vector<string>ans;
		PrintAll(temp,out,ans);
		sort(ans.begin(), ans.end());
		for(auto it:ans)cout<<it<<endl;
	}
};
int main() {
	Tries t;
	int n;cin>>n;
	string str;
	for(int i=0;i<n;i++){
		cin>>str;
		t.AddWord(str);
	}
	cin>>n;
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		t.Suggestion(str);	
	}
	return 0;
}
