#include <iostream>
using namespace std;
void magicalPark(char a[][100], int m, int n, int k, int s)
{
    //To break out of the outter loop:
    int p=0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //checking character of the park
            char ch = a[i][j];
            if (s < k)
            {
                //Missing:
                p=1;  
                break;
            }
            if (ch == '.')
            {
                s = s - 2;
            }
            else if (ch == '*')
            {
                s = s + 5;
            }
            else
            {
                break;
            }
            if (j != n - 1)
            {
                s--;
            }
        }

        //Missing:
        if(p==1)
            break;
    }

    if (s > k)
    {
        cout << "Yes" << endl;
        cout << s << endl;
    }
    //Missing:
    else 
        cout<<"No";
}

int main()
{
    char park[100][100];
    int m, n, k, s;
    cin>>m>>n>>k>>s;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //cout << "enter the character" << endl;
            cin >> park[i][j];
        }
    }
    magicalPark(park, m, n, k, s);
    return 0;
}
