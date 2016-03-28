
// Problem#: 10480
// Submission#: 2754357
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int N;

struct  point {
    long long  x,y;
    point(long long  x,long long  y):x(x),y(y){
    }
    point(){
    }
};
point last;


struct mirror{
    point lo;
    int type;
    mirror(point x,int type):lo(x),type(type){

    }
    mirror(){

    }
}all[210];
map< vector<long long  > ,int > vis;

bool cansee(){
    point t = point(0,0);
    point direct = point(1,0);
    vis.clear();

    while(1){
        vector<long long  > fl;
        fl.push_back(t.x);
        fl.push_back(t.y);
        fl.push_back(direct.x);
        fl.push_back(direct.y);
        if(vis[fl] > 0)return false;
        else {
            vis[fl] ++;
        }
        long long dis = 0;
        int index = -1;
        point k =  point(t.x + direct.x,t.y + direct.y);
        for(int i = 0 ; i <= N;i ++){
            long long  tt = (k.x - t.x) * (all[i].lo.x - k.x) + (k.y - t.y) * (all[i].lo.y - k.y);
            bool flag = false;
            if(k.x == all[i].lo.x && k.y == all[i].lo.y)flag = true;
            if((tt > 0 || flag) && ((k.x - t.x) * (all[i].lo.y - k.y) ==  (all[i].lo.x - k.x) * (k.y - t.y))){
                if(index == -1){
                    index = i;
                    dis = ((long long )all[i].lo.x - t.x)*(all[i].lo.x - t.x) + ((long long )all[i].lo.y - t.y)* (all[i].lo.y - t.y);
                }
                else {
                    long long dis2 = ((long long )all[i].lo.x - t.x)*(all[i].lo.x - t.x) + ((long long )all[i].lo.y - t.y)* (all[i].lo.y - t.y);
                    if(dis2 < dis){
                        dis = dis2;
                        index = i;
                    }
                }
            }
        }
        if(index == N){
            return true;
        }
        else if(index == -1){
            return false;
        }
        else {

            t = all[index].lo;
            if(all[index].type == 1){
                if(direct.x == 1 && direct.y == 0){
                    direct.x = 0;
                    direct.y = 1;
                }
                else if(direct.x == 0 && direct.y == -1){
                    direct.x = -1;
                    direct.y = 0;
                }
                else if(direct.x == -1 && direct.y == 0){
                    direct.x = 0;
                    direct.y = -1;
                }
                else if(direct.x == 0 && direct.y == 1){
                    direct.x = 1;
                    direct.y = 0;
                }
            }
            else if(all[index].type == 2){
                if(direct.x == 1 && direct.y == 0){
                    direct.x = 0;
                    direct.y = -1;
                }
                else if(direct.x == 0 && direct.y == -1){
                    direct.x = 1;
                    direct.y = 0;
                }
                else if(direct.x == -1 && direct.y == 0){
                    direct.x = 0;
                    direct.y = 1;
                }
                else if(direct.x == 0 && direct.y == 1){
                    direct.x = -1;
                    direct.y = 0;
                }
            }
        }
    }
}


int main(){
    cin >> N >> last.x >> last.y;
    for(int i = 0 ;i < N;i ++){
        char k;
        cin >> all[i].lo.x >> all[i].lo.y >> k;
        if(k == '/'){
            all[i].type = 1;
        }
        else {
            all[i].type = 2;
        }
    }
    all[N].lo = last;
    if(cansee()){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0;i < N;i ++){
        all[i].type = 3- all[i].type;
        if(cansee()){
            cout << i + 1 << endl;
            return 0;
        }
        all[i].type = 3 - all[i].type;
    }
    cout << -1 << endl;
    return 0;
}                                 