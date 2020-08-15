#include <iostream>
#include <bits/stdc++.h>
#include<string>
using namespace std;

long stoint(string s)
{
    long i,j=0;
    i = 0;
    while(s[j] >= '0' && s[j] <= '9')
    {
        i = i * 10 + (s[j] - '0');
        j++;
    }
    return i;
}

bool is_cb_number(string s)
{
    long long num = stoint(s);
    if (num == 0 || num == 1) 
    {
        return false;
    }
    int arr[10] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };

        for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) 
        {
            if (num == arr[i]) 
            {
                return true;
            }
        }

        for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) 
        {
            if (num % arr[i] == 0) {
                return false;
            }
        }

    return true;
}

bool is_valid(bool * visited, int l, int r)
{
    for(int i=l;i<r;i++)
    {
        if(visited[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    long count = 0;
    bool* visited = new bool[n];
    for(int i=0; i<s.length(); i++)             //ADDED
    {
        visited[i]=false;
    }
    for(int i=1; i <= s.length(); i++)
    {
        for(int j=0; j<=s.length()-i; j++)
        {   
            int e = j+i;
            string sub = s.substr(j, e-j);
            if(is_cb_number(sub) && is_valid(visited,j,e))
            {
                count++;
                for(int k=j;k<e;k++)
                {
                    visited[k]=true;
                }
            }
        }
    }
    cout<<count<<endl;
    return 0;
}
