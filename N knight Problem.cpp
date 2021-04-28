#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<string> vec;
int cc=0;
int X[8] = { 2, 1, -1, -2, -2, -1, 1, 2 }; 
int Y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 }; 
bool isSafe(int board[][15],int r,int c,int n){
	for (int i = 0; i < 8; i++) { 
        int x = r + X[i]; 
        int y = c + Y[i]; 
        if (x >= 0 && y >= 0 && x < n && y < n && board[x][y]) {
            return false;
        }
    } 
    return true;
}
void solveNKnight(int board[][15],int r,int c,int n,int count){
	if(count==n){  
		string s;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]){
                    s+= "{";
					s+=to_string(i);
					s+="-";
					s+=to_string(j);
					s+="} ";
				}
            }
        }
		vec.push_back(s);
        return ;
	}
	//recursive call
	for(int i=r;i<n;i++){
		for(int j=c;j<n;j++){
			if(isSafe(board,i,j,n) && !board[i][j]){
				board[i][j]=1;
                solveNKnight(board,r,c,n,count+1);      
				board[i][j]=0; 	
			}else{
				continue;
			}
			
		}
	}
}
int main(){
	int n;
	cin>>n;
    int board[15][15]={0};
	solveNKnight(board,0,0,n,0);
	sort(vec.begin(), vec.end());
  	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	for(int i=0;i<vec.size();i++)
	{
		if(i!=vec.size()-1)
		cout<<vec[i]<<" ";
		else
		cout<<vec[i];
	}
	cout<<endl<<vec.size();
	return 0;
}
