#include<bits/stdc++.h>
using namespace std;
#define N 205

 int f[N][N], n, k;
 bool h[N];

 int main()
 {
     int t, d;
     scanf("%d", &t);
     while(t--)
     {
         scanf("%d%d", &n, &k);
         memset(h, 0, sizeof h);
        memset(f, 0, sizeof f);
         f[0][0] = 1;
         for(int i = 1; i <= k; i++)
         {
             scanf("%d", &d);
             h[d] = 1;
         }
         for(int i = 1; i <= 2 * n; i++)
         {
             for(int j = 0; j <= 2 * n; j++)
             {
                if(h[i])
                 {   
                     if(j != 0)
                         f[i][j] = f[i-1][j-1];
                     else
                         f[i][j] =  0;
                 }
                 else
                 {
                     if(j != 0)
                         f[i][j] = f[i-1][j-1] + f[i-1][j+1];
                     else
                         f[i][j] = f[i-1][j+1];
                 }
             }
         }
         printf("%d\n", f[2*n][0]);
     }
     return 0;
}
