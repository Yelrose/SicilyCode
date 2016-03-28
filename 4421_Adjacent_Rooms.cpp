
// Problem#: 4421
// Submission#: 1210969
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct point{
    int x;
    int y;
};

int energy[50][50];

struct V_E{
    point A;
    point B;
    int kk;
}All[2500000];
int fa[2500000];
int findFa(int i)
{
   if(fa[i] != i)
   {
       return findFa(fa[i]);
   }
   return i;
}
int Energy(point A)
{
    return energy[A.x][A.y];
}
bool cmp(V_E a, V_E b)
{
    return a.kk < b.kk;
}

void zui()
{
    int row,col;
    cin >> row >> col;
    for(int i = 0;i < row;i ++)
    {
        for(int j = 0;j < col;j ++)
        {
            cin >> energy[i][j];
        }
    }
    int all = 0;
    for(int i = 0;i < row;i ++)
    {
        for(int j = 1;j < col;j ++)
        {
            point A,B;
            A.x =i;
            B.x = i;
            A.y = j - 1;
            B.y = j;
            All[all].A = A;
            All[all].B = B;
            All[all].kk = pow(Energy(A) - Energy(B),2);
            all++;
        }
    }
    for(int i = 0;i < col;i ++)
    {
        for(int j = 1;j < row;j ++)
        {
            point A,B;
            A.x = j;
            B.x = j - 1;
            A.y = i;
            B.y = i;
            All[all].A = A;
            All[all].B = B;
            All[all].kk = pow(Energy(A) - Energy(B),2);
            all++;
        }
    }
    sort(All,All + all,cmp);
    for(int i = 0;i < row;i ++)
    {
        for(int j = 0;j < col;j ++)
        {
            fa[i * col + j] = i * col + j;
        }
    }
    int total = 0;
    for(int i = 0;i < all;i ++)
    {
        //cout << "xx" << endl;
        int x = All[i].A.x * col + All[i].A.y;
        int y = All[i].B.x * col + All[i].B.y;
        if(findFa(x)!= findFa(y)){
             total += All[i].kk;
            fa[findFa(x)] = y;
        }
    }

    cout << total << endl;


}

int main()
{
    int T;
    cin >> T;
    for(int i = 0;i < T;i ++ )
    zui();
}                                 