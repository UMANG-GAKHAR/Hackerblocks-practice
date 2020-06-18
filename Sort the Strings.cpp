#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int key;
string reversed , cmp_type;
bool compare(string s1 , string s2)
{
    char *ptr[2];
    char str1[100];
    char str2[100];
    int i;
    for(i = 0 ; s1[i] != '\0' ; i++)
    {
        str1[i] = s1[i];
    }
    str1[i] = '\0';
    for(i = 0 ; s2[i] != '\0' ; i++)
    {
        str2[i] = s2[i];
    }
    str2[i] = '\0';
    int k = key;
    ptr[0] = strtok(str1 , " ");
    k--;
    while(k != 0 and ptr[0] != NULL)
    {
        ptr[0] = strtok(NULL , " ");
        k--;
    }
    k = key;
    ptr[1] = strtok(str2 , " ");
    k--;
    while(k != 0 and ptr[1] != NULL)
    {
        ptr[1] = strtok(NULL , " ");
        k--;
    }
    bool ans;
    string x1 = ptr[0];
    string x2 = ptr[1];
    bool test = cmp_type == "numeric";
    if(test)
    {
        ans = (stoi(x1) < stoi(x2));
    }
    else
    {
        ans = (x1 < x2);
    }
    if(reversed == "false")
    {
        return ans;
    }
    return !ans;
}
int main()
{
    string s[60];
    int n;
    cin>>n;
    cin.get();
    for(int i = 0 ; i < n ; i++)
    {
        getline(cin , s[i]);
    }
    cin>>key>>reversed>>cmp_type;
    sort(s , s + n , compare);
    for(int i = 0 ; i < n ; i++)
    {
        cout<<s[i]<<endl;
    }
    return 0;
}
