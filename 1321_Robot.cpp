
// Problem#: 1321
// Submission#: 1206268
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Point{
    int value;
    int color;
}All[101][101];
int fuel[101][101];


struct zuobiao{
    int x;
    int y;
};
zuobiao move[4];
queue<zuobiao> orth;

void dijk()
{
    move[0].x = 1;
    move[0].y = 0;
    move[1].x = -1;
    move[1].y = 0;
    move[2].x = 0;
    move[2].y = 1;
    move[3].x = 0;
    move[3].y = -1;
    int col,row;
    cin >> row >> col;
    for(int i = 0;i < 101;i ++)
    {
        for(int j = 0;j < 101;j ++)
        {
            All[i][j].color = 3;
        }
    }
    for(int i = 1;i <= row;i++)
    {
        for(int j = 1;j <= col;j ++)
        {
            All[i][j].value = 99999999;
            All[i][j].color = 0;
            cin >> fuel[i][j];
        }
    }
    zuobiao start;
    zuobiao end;
    cin >> start.x >> start.y;
    cin >> end.x >> end.y;
    All[start.x][start.y].color = 1;
    All[start.x][start.y].value = fuel[start.x][start.y];
    orth.push(start);
    while(!orth.empty()){
        zuobiao temp;
        temp = orth.front();
        All[temp.x][temp.y].color = 2;
        orth.pop();
        zuobiao new_one;
        for(int i = 0;i < 4;i ++)
        {

                new_one.x = temp.x + move[i].x;
                new_one.y = temp.y + move[i].y;
                if(All[new_one.x][new_one.y].color == 3)continue;
                if(All[new_one.x][new_one.y].value > All[temp.x][temp.y].value + fuel[new_one.x][new_one.y])
                {
                    All[new_one.x][new_one.y].value = All[temp.x][temp.y].value + fuel[new_one.x][new_one.y];
                    All[new_one.x][new_one.y].color = 1;
                    orth.push(new_one);
                }


        }
    }
    /*for(int i = 1;i <= row;i ++)
    {
        for(int j = 1;j <= col;j ++)
        {
            cout << All[i][j].value << " ";
        }
        cout << endl;
    }*/
    cout << All[end.x][end.y].value << endl;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0;i < n;i ++)
    {
        dijk();
    }

}                                 