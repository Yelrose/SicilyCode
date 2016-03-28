
// Problem#: 1152
// Submission#: 1211684
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <stack>
#include <cstring>
#define ROW 5
#define COL 6
using namespace std;


struct point{
    int x;
    int y;
}Move[8];

stack<point > shun;

int chass[ROW + 1][COL + 1];
int reach[ROW + 1][COL + 1];

bool visit(point a){
    return reach[a.y][a.x];
}
bool exit(point b){
    return (b.x <= COL && b.x >= 1 && b.y <= ROW && b.y >= 1 );
}
int count(point b){
    int num = 0;
    for(int i = 0;i < 8;i ++){
        point temp;
        temp.x = b.x + Move[i].x;
        temp.y = b.y + Move[i].y;
        if(exit(temp))num ++;
    }
    return num;
}
int dfs(point A,int tim);
void start(int dsf)
{
    for(int i = 1;i <= ROW;i ++)
    {
        for(int j = 1;j <= COL;j ++)
        {
            chass[i][j] = (i - 1) * COL + j;
            //cout << chass[i][j] << " ";
        }
        //cout << endl;
    }
    memset(reach,0,sizeof(reach));
    int start;
    start = dsf;
    point beg;

    beg.y = (start - 1) / COL + 1;
    beg.x = start - (beg.y - 1) * COL;
    //cout << beg.y <<" " << beg.x << endl;
    //cout << chass[beg.y][beg.x] << endl;
    dfs(beg,1);
    int besf = 0;
    while(!shun.empty()){
        if(besf ++)
        {
            cout << " ";
        }
        point temp = shun.top();
        shun.pop();
        cout << chass[temp.y][temp.x];

    }
    cout << endl;
}

int dfs(point A,int tim){
    //cout << " exit"<<exit(A) << "  ";
    //cout << tim << " ";
    //cout << chass[A.y][A.x];
    //cout << "    x=" << A.x << " y=" << A.y << endl;
    if(tim == COL * ROW){
        shun.push(A);
        return 2;
    }
    reach[A.y][A.x] = 1;
    tim ++;
    int num[8];
    point zz[8];
    for(int i = 0;i < 8;i ++)
    {
        point B;
        B.x = A.x + Move[i].x;
        B.y = A.y + Move[i].y;
        zz[i].x = B.x;
        zz[i].y = B.y;
        if(exit(zz[i])){
        num[i] = count(zz[i]);
        }
        else num[i] = 9999;
    }
    for(int i = 0;i < 8;i ++){
        for(int j = 7;j > 0;j --)
        {
            if(num[j] < num[j - 1]){
                int temp = num[j];
                num[j]= num[j - 1];
                num[j - 1] = temp;
                point temp2;
                temp2.x = zz[j].x;
                temp2.y = zz[j].y;
                zz[j].x = zz[j - 1].x;
                zz[j].y = zz[j - 1].y;
                zz[j - 1].x = temp2.x;
                zz[j - 1].y = temp2.y;
            }
        }
    }
    for(int i = 0;i < 8;i ++){
        int k = 0;
        if(reach[zz[i].y][zz[i].x] == 0 && exit(zz[i]) ){
            k = dfs(zz[i],tim);
        }
        if(k == 2)
        {
            shun.push(A);
            return 2;
        }
    }
    reach[A.y][A.x] = 0;
    return 0;
}


int main()
{
    Move[0].x = 1;Move[0].y = 2;
    Move[1].x = 1;Move[1].y = -2;
    Move[2].x = -1;Move[2].y =2;
    Move[3].x = -1;Move[3].y = -2;
    Move[4].x = 2;Move[4].y = 1;
    Move[5].x = 2;Move[5].y = -1;
    Move[6].x = -2;Move[6].y =1;
    Move[7].x = -2;Move[7].y = -1;
    int k;
    while(cin >> k && k != -1){
        start(k);
    }
}                                 