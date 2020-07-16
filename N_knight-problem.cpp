#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll board[1000][10000];
ll N;

bool check(ll i, ll j){
    if(i-2>=0 && j+1>=0 && i-2<N && j+1<N && board[i-2][j+1]==1)
        return false;
    if(i-1>=0 && j+2>=0 && i-2<N && j+2<N && board[i-1][j+2]==1)
        return false;
    if(i+1>=0 && j+2>=0 && i+1<N && j+2<N && board[i+1][j+2]==1)
        return false;
    if(i+2>=0 && j+1>=0 && i+2<N && j+1<N && board[i+2][j+1]==1)
        return false;
    if(i+2>=0 && j-1>=0 && i+2<N && j-1<N && board[i+2][j-1]==1)
        return false;
    if(i+1>=0 && j-2>=0 && i+1<N && j-2<N && board[i+1][j-2]==1)
        return false;
    if(i-1>=0 && j-2>=0 && i-1<N && j-2<N && board[i-1][j-2]==1)
        return false;
    if(i-2>=0 && j-1>=0 && i-2<N && j-1<N && board[i-2][j-1]==1)
        return false;
    return true;
}
bool solve(int cnt, int i, int j){

    if(cnt > N){

        return false;
    }

    if(i >= N){

        return false;
    }
    if(cnt == N){

        //totalCongigutation++;
        for(ll i=0;i<N;i++)
        {
            for(ll j=0;j<N;j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        return false;
    }

    if(j >= N){

        return solve(cnt, i+1, 0);
    }

        if(check(i, j)){

            board[i][j] = 1;

            bool isplace = solve(cnt+1, i, j+1);

            if(isplace){

                return true;
            }
            board[i][j] = 0;
        }
    return solve(cnt, i, j+1);
    return false;
}
int main() {
    cin>>N;
    for(ll i=0; i<N;i++){
        for(ll j=0; j<N; j++){
            board[i][j] = 0;
        }
    }
    solve(0, 0,0);
    cout<<endl;
}
