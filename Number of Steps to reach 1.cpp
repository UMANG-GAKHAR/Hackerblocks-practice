#include <iostream>
using namespace std;
class Solution {
public:
    int integerReplacement(int n) {
        if(n==2147483647)
            return integerReplacement(n-1);
        if(n==1)
            return 0;
        if(n%2==0)
            return integerReplacement(n/2)+1;
        else
        {
            if(n==3||n%4==1)
            {
                return integerReplacement(n-1)+1;
            }
            else
            {
                return integerReplacement(n+1)+1;
            }
        }
    }
};
int stringToInteger(string input) {
    return stoi(input);
}
int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);

        int ret = Solution().integerReplacement(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}
