
// Problem#: 1155
// Submission#: 1207611
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

queue<int > visit;

struct V_E{
    int start;
    int end;
}All[20000];
bool cmp(V_E a,V_E b){
    return a.start < b.start;
}
int color[200];

void bfs(int city)
{
    while(!visit.empty())
    {
        visit.pop();
    }
    int road;
    memset(color,0,sizeof(color));
    cin >> road;
    for(int i = 0;i < road;i ++)
    {
        cin >> All[i].start >> All[i].end;
    }
    sort(All,All + road,cmp);
    if(All[0].start != 0){
        cout << "I can't post the letter" << endl;
        return;
    }

    visit.push(0);
    while(!visit.empty())
    {
        int temp = visit.front();
        visit.pop();
        color[temp] = 1;
        for(int i = 0;i < road;i ++)
        {
            if(All[i].start == temp && color[All[i].end] == 0)
            {

                visit.push(All[i].end);
            }
            if(All[i].start > temp) break;
        }
    }
    if(color[city - 1] == 1)cout << "I can post the letter" <<  endl;
    else cout <<"I can't post the letter" << endl;
    return;
}

int main()
{
    int T;
    while(cin >> T && T != 0)
    {
        bfs(T);
    }
}                                 