
// Problem#: 1936
// Submission#: 1212622
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;


string qipan[8][8] = {
    {"a1","a2","a3","a4","a5","a6","a7","a8"},
    {"b1","b2","b3","b4","b5","b6","b7","b8"},
    {"c1","c2","c3","c4","c5","c6","c7","c8"},
    {"d1","d2","d3","d4","d5","d6","d7","d8"},
    {"e1","e2","e3","e4","e5","e6","e7","e8"},
    {"f1","f2","f3","f4","f5","f6","f7","f8"},
    {"g1","g2","g3","g4","g5","g6","g7","g8"},
    {"h1","h2","h3","h4","h5","h6","h7","h8"}
};
int dis[8][8];
int visit[8][8];
int move_1[2] = {-1,1};
int move_2[2] = {-2,2};
struct point{
    int x;
    int y;
};
queue<point >all;
bool inmap(int x,int y){
    return x >= 0 && x < 8 && y >=0 && y < 8;
}

void bfs(){
    memset(dis,0,sizeof(dis));
    memset(visit,0,sizeof(visit));
    string start,end;
    cin >> start >> end;
    point st,en;
    st.y = start[0] - 'a';
    st.x = start[1] - '1';
    //cout << st.y << " " <<st.x;
    en.y = end[0] - 'a';
    en.x = end[1] - '1';
    all.push(st);
    dis[st.y][st.x] = 0;
    while(!all.empty()){
        point temp;
        temp.x = all.front().x;
        temp.y = all.front().y;
        all.pop();
        visit[temp.y][temp.x] = 1;
        for(int i = 0;i < 2;i ++){
            point tem;
            for(int j = 0;j < 2;j ++){
                tem.y = temp.y + move_2[i];
                tem.x = temp.x + move_1[j];
                if(inmap(tem.y,tem.x)){
                    if(visit[tem.y][tem.x] == 0){
                        all.push(tem);
                        dis[tem.y][tem.x] = dis[temp.y][temp.x] + 1;
                    }
                }
            }
        }
        for(int i = 0;i < 2;i ++){
            point tem;
            for(int j = 0;j < 2;j ++){
                tem.y = temp.y + move_1[i];
                tem.x = temp.x + move_2[j];
                if(inmap(tem.y,tem.x)){
                    if(visit[tem.y][tem.x] == 0){
                        all.push(tem);
                        dis[tem.y][tem.x] = dis[temp.y][temp.x] + 1;
                    }
                }
            }
        }
    }
    
    cout << "To get from " << start << " to " << end << " takes " << dis[en.y][en.x] << " knight moves." << endl;
}

int main(){
    int T;
    cin >> T;
    for(int i = 0;i < T;i ++){
        bfs();
    }
}                                 