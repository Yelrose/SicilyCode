
// Problem#: 1146
// Submission#: 914946
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
#include<algorithm>
using namespace std;
int t,m;
int x[101][1001];

struct DATA{int time;int v;}all[101];
int max(int a,int b);
int fuction(int i,int leftTime);
int main()
{
    cin>>t>>m;
    for(int i=1;i<=m;i++)
        cin>>all[i].time>>all[i].v;
    for(int i = 0;i <= t; i++)
    {
        if(all[m].time <= i)x[m][i] = all[m].v;
        else x[m][i] = 0;

    }
    for(int i=m-1;i>=1;i--)
    {
        for(int j=0;j<=t;j++)
        {
            if(j-all[i].time<0)x[i][j]=x[i+1][j];
            else    x[i][j]=max(x[i+1][j],(x[i+1][(j-all[i].time)]+all[i].v));
        
        }
    
    }
    cout<<x[1][t]<<endl;
    return 0;

}

int max(int a,int b)
{
    if(a>b)return a;
    else return b;
}                                 