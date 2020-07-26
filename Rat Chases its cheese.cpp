#include<iostream>
using namespace std;

bool ratInMaze(char maze[10][10],int soln[10][10],int i,int j,int n,int m){

    //To check for the starting and the ending index also
     if(i>n||j>m||i<0||j<0 || soln[i][j]){
        return false;
    }
    if(maze[i][j]=='X'){
        return false;
    }

    if(i==n&&j==m){
        soln[n][m]=1;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            cout<<soln[i][j]<<" ";
        }
        cout<<endl;
    }        

        return true;
    }
    
   
    
    bool right=false,down=false,up=false,left=false;
    soln[i][j] = 1;
    
    if(i+1<=n && soln[i+1][j]==0){
        down = ratInMaze(maze,soln,i+1,j,n,m);
    }
    //Modiificatons:
    if(j+1<=m && soln[i][j+1]==0 && !down){
        right = ratInMaze(maze,soln,i,j+1,n,m);
    }
    if(i-1>=0 && soln[i-1][j]==0 && !down && !right){
        up = ratInMaze(maze,soln,i-1,j,n,m);
    }
    if(j-1>=0 && soln[i][j-1]==0 && !down && !right && !up){
        left = ratInMaze(maze,soln,i,j-1,n,m);
    }

    if(right||down||left||up){
        return true;
    }
    //Modification:
    soln[i][j] = 0;
    
    return false;
}


int main() {
    int n,m;
    cin>>n>>m;
    
    char maze[10][10];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>maze[i][j];
        }
    }
    
    int soln[10][10]={0};
    
    bool ans = ratInMaze(maze,soln,0,0,n-1,m-1);
    
    if(ans==false){
        cout<<"NO PATH FOUND";
    }
    
	return 0;
}
