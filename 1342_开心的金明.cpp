
// Problem#: 1342
// Submission#: 1015635
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
using namespace std;
int max(int a,int b);
struct DATA
{
    int value;
    int wealth;
    int import;
}all[26];
int x[26][30001];
void judge(int n,int m)
{

    for(int i = 1;i <= m;i ++)
    {
        cin >> all[i].value >> all[i].import;
        all[i].wealth = all[i].value * all[i].import;
    }
    for(int i = 0;i <= n; i++)
    {
        if(all[m].value <= i)x[m][i] = all[m].wealth;
        else x[m][i] = 0;

    }
    for(int i=m-1;i>=1;i--)
    {
        for(int j=0;j<=n;j++)
        {
            if(j-all[i].value<0)x[i][j]=x[i+1][j];
            else    x[i][j]=max(x[i+1][j],(x[i+1][(j-all[i].value)]+all[i].wealth));

        }

    }
    cout<<x[1][n]<<endl;


}

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        judge(n,m);
    }
}

int max(int a,int b)
{
    if(a > b)return a;
    else return b;
}                                 