
// Problem#: 1784
// Submission#: 2053922
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 8014
// Submission#: 2053892
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <queue>
#include <iomanip>
#include <cstring>
using namespace std;

double edge[101][101];
double ml[101];
bool inq[101];
queue<int > bfs;
int n;
void go(){
    int s,e;
    cin >> n >> s >> e;
    for(int i = 1;i <= n;i ++ ){
        for(int j= 1;j <= n;j ++){
            cin >> edge[i][j];
        }
    }
    memset(ml,0,sizeof(ml));
    ml[s] = 1;
    bfs.push(s);
    inq[s] = 1;
    while(!bfs.empty()){
        int t = bfs.front();
        bfs.pop();
        inq[t] = 0;
        for(int i = 1;i <= n;i ++){
            if(ml[i] < ml[t]*(1 - edge[t][i])){
                ml[i] = ml[t] * (1 - edge[t][i]);
                if(!inq[i]){
                    inq[i] = 1;
                    bfs.push(i);
                }
            }
        }
    }
    cout <<setprecision(2) << fixed <<  ml[e] << endl;


}


int main(){
    int T;
    cin >> T;
    while(T --){
        go();
    }
}                                 