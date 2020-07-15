#include <bits/stdc++.h>
using namespace std;

#define int             long long int
#define ld              long double
#define lop(i, a, b)    for (int i = a; i < b; i++)
#define rlop(i, b, a)   for (int i = b-1; i >= a; i--)
#define F               first
#define S               second
#define pb              push_back
#define si              set <int>
#define vi              vector <int>
#define pii             pair <int, int>
#define vpi             vector <pii>
#define mii             map <int, int>
#define spi             set <pii>
#define usi             unordered_set <int>
#define endl            "\n"
#define sz(x)           ((int) x.size())
#define all(p)          p.begin(), p.end()
#define que_max         priority_queue <int>
#define que_min         priority_queue <int, vi, greater<int>>
#define bug(...)        __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)        for (auto x : a) cout << x << " "; cout << endl
#define mset(a, b, c)   lop (i, 0, c) a[i] = b
#define print1(a, n)    lop (i, 0, n) cout << a[i] << " "; cout << endl

inline int pow(int a, int b)
{
     int x = 1;
     while (b)
     {
          if (b & 1) x *= a;
          a *= a;
          b >>= 1;
     }
     return x;
}

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
     const char* comma = strchr (names + 1, ',');
     cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}

const int N = 25;

struct P {
     int x1, x2, y1, y2, t;
};

P p, a[N];
int n, vst[N],ans;

void robot(int tim, pii v)
{
     ans=min(ans,tim+abs(v.F - p.x2) + abs(v.S - p.y2));

     lop(i, 0, n)
     {
          if (vst[i]) continue ;

          int dis = abs(a[i].x1 - v.F) + abs(a[i].y1 - v.S) + a[i].t;
          vst[i]++;
          robot(tim + dis, {a[i].x2, a[i].y2});

          dis = abs(a[i].x2 - v.F) + abs(a[i].y2 - v.S) + a[i].t;
          robot(tim + dis, {a[i].x1, a[i].y1});
          vst[i]--;

     }
}

int32_t main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0); cout.tie(0);

     int tt; cin >> tt;
     lop(j, 1, tt + 1)
     {
          cin >> n;
          cin >> p.x1 >> p.y1 >> p.x2 >> p.y2;

          lop(i, 0, n) cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2 >> a[i].t;

          ans = abs(p.x1-p.x2)+abs(p.y1-p.y2);
          robot(0, {p.x1, p.y1});
          cout << "#" << j << " : " << ans << endl;
     }

     return 0;
}
