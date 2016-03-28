
// Problem#: 4186
// Submission#: 1094687
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;

int a[10][10];
int b[10][10];
int c[10][10];

void judge(int n)
{
    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < n;j ++)
            cin >> a[i][j];
    }
    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < n;j ++)
            cin >> b[i][j];
    }
    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < n;j ++)
            c[i][j] = b[i][j] + a[i][j];
    }
    for(int i = 0;i < n;i ++)
    {
        for(int j = 0;j < n;j ++)
        {
            if(j > 0)cout << " ";
            cout << c[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int n;
    while(cin >> n && n != 0)
    {
        judge(n);
    }
}                                 