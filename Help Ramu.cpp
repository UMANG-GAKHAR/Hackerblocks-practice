#include <iostream>
using namespace std;
int main ()
{
    int testcase;
    cin >> testcase;
    int c1, c2, c3, c4, n, m;
    int i;
    int rick[1005], cab[1005];
    while (testcase--)
    {
        cin >> c1 >> c2 >> c3 >> c4;
        cin >> n >> m;
        for (i = 0; i < n; i++)
            cin >> rick[i];
        for (i = 0; i < m; i++)
            cin >> cab[i];
        int costr = 0, costc = 0, min_cost;
        for (i = 0; i < n; i++)
            costr += min(c1*rick[i], c2);

        costr = min(costr, c3);
        for (i = 0; i < m; i++)
            costc += min(c1*cab[i], c2);

        costc = min(costc, c3);
        int cost;
        cost = costc + costr;
        min_cost = min(c4, cost);
        cout << min_cost << endl;
    }
    return 0;
}
