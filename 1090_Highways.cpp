
// Problem#: 1090
// Submission#: 1207595
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct V_E{
    int start;
    int end;
    int dis;
}All[125000];
int color[500];

int biao[500][500];
bool cmp(const V_E a,const V_E b)
{
    return (a.dis < b.dis);
}

int Fa(int i)
{
    if(color[i] != i)
    {
        return Fa(color[i]);
    }
    return i;
}

void zui()
{

    int vil;
    cin >> vil;
    for(int i = 0;i < vil;i ++)
    {
        for(int j = 0;j < vil;j ++)
        {
            cin >> biao[i][j];
        }
    }
    int count  = 0;
    for(int i = 0;i < vil;i ++)
    {
        for(int j = i + 1;j < vil;j ++)
        {
            All[count].start = i;
            All[count].end = j;
            All[count].dis = biao[i][j];
            count ++;
        }
    }
    sort(All,All + count,cmp);
    V_E temp;
    int con = vil - 1;
    for(int i = 0;i < vil;i ++)
    {
        color[i] = i;
    }
    for(int i = 0;i < count;i ++)
    {
        if(Fa(All[i].start) != Fa(All[i].end))
        {
            int x = Fa(All[i].start);
            int y = Fa(All[i].end);
            color[x] = y;
            temp = All[i];
            con --;
            if(con == 0) break;
        }
    }
    cout << temp.dis << endl;
}

int main()
{
    int T;
    cin >> T;
    for(int i = 0;i < T;i ++)
    {
        zui();
        if(i < T - 1)cout  << endl;
    }
}                                 