
// Problem#: 2002
// Submission#: 965998
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;
bool state[750][750];
char grass[750][750];
int w,h;
int row,col;
void span(int & count);
void bfs()
{
    for(int i = 0;i < h;i ++)
    {
        for(int j = 0;j < w;j ++)
        {
            if(grass[i][j] == '*')state[i][j] = true;
            else state[i][j] = false;
        }
    }
    int a;
    int b = 0;
    for(int i = 0;i < h;i ++)
    {
        for(int j = 0;j < w;j ++)
        {
            a = 0;
            row = i;
            col = j;
            span(a);
            if(b < a)b = a;
        }
    }
    cout << b << endl;
}
void span(int & count)
{
    if(row < 0 || row > h - 1)return;
    if(col < 0 || col > w - 1)return;
    if(state[row][col] == true)return;
    else
    {
        state[row][col] = true;
        count ++;
        row --;
        span(count);
        col ++;
        span(count);
        col --;
        col --;
        span(count);
        row ++;
        col += 2;
        span(count);
        col -= 2;
        span(count);
        col ++;
        row ++;
        span(count);
        col ++;
        span(count);
        col -= 2;
        span(count);
        col ++;
        row --;
    }
}
int main()
{
    cin >> w >> h;
    for(int i = 0;i < h;i ++)
    {
        for(int j = 0;j < w;j ++)
            cin >> grass[i][j];
    }
    bfs();
}                                 