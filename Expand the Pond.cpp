#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

const int kMaxN = 1e3 + 5;

int el[kMaxN][kMaxN];

bool visited[kMaxN][kMaxN];
int group_id[kMaxN][kMaxN];

int next_group = 1;
int group_size[kMaxN * kMaxN];

const int dx[4] = {0, 0, -1, +1};
const int dy[4] = {-1, +1, 0, 0};

void Expand(int x, int y) {
    vector<pair<int, int>> fill_q = {{x, y}};
    visited[x][y] = true;

    // get the group-id of the current black shape
    int g = next_group++;

    // expand in all cells that are reacheable from the starting {x, y} positions
    // it doesn't matter if we expand in the fill using a vector or a queue
    // Using a queue expands in the cells in increasing order regarding the distance
    // to the start position.
    // Using a stack can be compared to a DFS traversal, more than a BFS one, but since
    // we only need to fill the black shape, both of them work just fine.
    while (fill_q.size()) {
        int x = fill_q.back().first;
        int y = fill_q.back().second;
        fill_q.pop_back();

        group_size[g] += 1;
        group_id[x][y] = g;

        for (int d = 0; d < 4; d += 1) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (not visited[nx][ny] and el[nx][ny]) {
                visited[nx][ny] = true;
                fill_q.push_back({nx, ny});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= m; j += 1) {
            cin >> el[i][j];
        }
    }

    // We'll give each black shape a 'group-id' so we can see if 2 cells belong to the same
    // black shape. While expanding a group, we'll compute the size of it as well, so when
    // we need to merge 2 or more shapes, we'll know the resulting size of the group.
    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= m; j += 1) {
            if (visited[i][j] == false and el[i][j]) {
                // If a cell is black and not visited, expand a new group that contains that cell
                Expand(i, j);
            }
        }
    }

    int mx = 0;
    vector<int> ap(5, 0);
    for (int i = 1; i <= n; i += 1) {
        for (int j = 1; j <= m; j += 1) {
            // only check white cells
            if (el[i][j]) {
                continue;
            }

            // get all the groups that are near our cell.
            // white cells or the border cells belong to group 0 which has size 0
            vector<int> groups = {};
            for (int d = 0; d < 4; d += 1) {
                groups.push_back(group_id[i + dx[d]][j + dy[d]]);
            }

            // make the groups unique, so we count a group only 1 time when merging groups
            sort(groups.begin(), groups.end());
            groups.resize(unique(groups.begin(), groups.end()) - groups.begin());

            // get the size of the new figure
            int s = 0;
            for (auto itr : groups) {
                s += group_size[itr];
            }

            // cound the new black cell the one that was just painted as well (the +1)
            mx = max(mx, s + 1);
        }
    }

    cout << mx << '\n';
    return 0;
}
