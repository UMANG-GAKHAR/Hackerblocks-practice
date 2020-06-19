#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Employee
{
    public:

    int salary;
    string name;

    Employee( int sal , string nam)
    {
        salary = sal;
        name = nam;
    }
};

bool operator>( string s1 , string s2 )
{
    int min = s1.size() < s2.size() ? s1.size() : s2.size(); 

    int index = 0;

    while( index < min && s1[index] == s2[index])
    {
        index++;
    }

    if( index >= min )
    {
        if( s1.size() > s2.size() ) return true;
        else return false;
    }

    if( s1[index] > s2[index] ) return true;
    else return false;

}

bool lol( Employee e1 , Employee e2 )
{
    if( e1.salary > e2.salary )
    {
        return true;
    }
    else
    if( e1.salary < e2.salary )
    {
        return false;
    }

    return e2.name > e1.name;
}

void sort2( vector<Employee> &v )
{
    sort( v.begin() , v.end() , lol);
}

int main()
{
    int n2;
    cin >> n2;

    int n;
    cin >> n;

    vector<Employee> v;

    for(int i = 0 ; i < n ; i++ )
    {
        string s;
        cin >> s;

        int n;
        cin >> n;

        Employee E( n , s);
        v.push_back(E);
    }

    sort2(v);

    for(int i = 0 ; i < n ; i++ )
    {
        if( v[i].salary < n2 ) break;

        cout << v[i].name << " " << v[i].salary << "\n";
    }

    return 0;
}
