

#include<bits/stdc++.h>
using namespace std;
string number;

long long mem[19][2][2][2][2][2][2][3][5][7];
string to_string_(long long num) {
     stringstream ss_var;
     ss_var << num;

     return ss_var.str();
}

long long solve(int pos, int flag, int two, int three, int five, int seven, int r2, int r3, int r5, int r7, int prev) {
     long long ans = 0;
     if (number.length() == pos) {
          if (two && (r2 != 0)) return 0;
          if (three && (r3 != 0)) return 0;
          if (five && (r5 != 0)) return 0;
          if (seven && (r7 != 0)) return 0;
          return 1; //Reason for return of 1
     }
     if (mem[pos][flag][two][three][five][seven][r2][r3][r5][r7] != -1) return mem[pos][flag][two][three][five][seven][r2][r3][r5][r7];
     int limit = number[pos] - '0';
     for (int i = 0; i < 10; ++i) {
          if (!flag && i > limit) break;
          if (__gcd(prev, i) == 1) continue;
          ans += solve(pos + 1, flag | (i < limit), (i == 2) | two, (i == 3) | three, (i == 5) | five, (i == 7) | seven, (r2 * 10 + i) % 2, (r3 * 10 + i) % 3, (r5 * 10 + i) % 5, (r7 * 10 + i) % 7, i);

     }
     mem[pos][flag][two][three][five][seven][r2][r3][r5][r7] = ans;

     return ans;
}

int main() {
     int t; cin >> t;
     while (t--) {
          long long l, r;
          cin >> l >> r;
          number = to_string_(r);
          memset(mem, -1, sizeof mem);
          long long pr_less_than_r = solve(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
          number = to_string_(l - 1);
          memset(mem, -1, sizeof mem);
          long long pr_less_than_l = solve(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
          if (l == 1) pr_less_than_l = 0;
          cout << pr_less_than_r - pr_less_than_l << endl;
     }
     return 0;
}
