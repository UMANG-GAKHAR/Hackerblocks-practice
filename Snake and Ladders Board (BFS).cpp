

// C++ program to find minimum number of dice throws required to
// reach last cell from first cell of a given snake and ladder
// board
#include<iostream>
#include <queue>
using namespace std;

// An entry in queue used in BFS
struct queueEntry
{
    int v;   // Vertex number
    int dist; // Distance of this vertex from source
};


int getMinDiceThrows(int move[], int N)
{
    // The graph has N vertices. Mark all the vertices as
    // not visited
    bool *visited = new bool[N];
    for (int i = 0; i < N; i++)
        visited[i] = false;

    // Create a queue for BFS
    queue<queueEntry> q;

    // Mark the node 0 as visited and enqueue it.
    visited[0] = true;
    queueEntry s = {0, 0}; // distance of 0't vertex is also 0
    q.push(s); // Enqueue 0'th vertex

    // Do a BFS starting from vertex at index 0
    queueEntry qe; // A queue entry (qe)
    while (!q.empty())
    {
        qe = q.front();
        int v = qe.v; // vertex no. of queue entry

        // If front vertex is the destination vertex,
        // we are done
        if (v == N-1)
            break;

        // Otherwise dequeue the front vertex and enqueue
        // its adjacent vertices (or cell numbers reachable
        // through a dice throw)
        q.pop();
        for (int j=v+1; j<=(v+6) && j<N; ++j)
        {
            // If this cell is already visited, then ignore
            if (!visited[j])
            {
                // Otherwise calculate its distance and mark it
                // as visited
                queueEntry a;
                a.dist = (qe.dist + 1);
                visited[j] = true;

                // Check if there a snake or ladder at 'j'
                // then tail of snake or top of ladder
                // become the adjacent of 'i'
                if (move[j] != -1)
                    a.v = move[j];
                else
                    a.v = j;
                q.push(a);
            }
        }
    }

    // We reach here when 'qe' has last vertex
    // return the distance of vertex in 'qe'
    return qe.dist;
}

// Driver program to test methods of graph class
int main()
{
    // Let us construct the board given in above diagram
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int moves[n];
        for(int j=0;j<n;j++)
        {
            moves[j]=-1;
        }
        for(int j=0;j<m;j++)
        {
            int k1,k2;
            cin>>k1>>k2;
            moves[k1-1]=k2;
        }
        for(int j=0;j<k;j++)
        {
            int k1,k2;
            cin>>k1>>k2;
            moves[k1-1]=k2;
        }
        cout << getMinDiceThrows(moves, n)<<endl;
    }
    // int N = 30;
    // int moves[N];
    // for (int i = 0; i<N; i++)
    //  moves[i] = -1;

    // // Ladders
    // moves[2] = 21;
    // moves[4] = 7;
    // moves[10] = 25;
    // moves[19] = 28;

    

    // cout << "Min Dice throws required is " << getMinDiceThrows(moves, N)<<endl;
    // return 0;
}
