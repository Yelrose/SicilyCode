
// Problem#: 1935
// Submission#: 1624063
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstring>
using namespace std;

int lvl[30];
char Pre[30];
char Mid[30];


void go(){
    cin >> Pre;
    cin >> Mid;
    memset(lvl,0,sizeof(lvl));
    int len = strlen(Pre);
    int max = 0;
    for(int i = 0;i < len;i ++){
        int j = 0;
        while(Mid[j] != Pre[i]){
            j ++;
        }
        int k = lvl[j];
        for(int z = j - 1;z >= 0;z --){
            if(lvl[z] < lvl[j])break;
            else if(lvl[z] == lvl[j]){
                lvl[z] = k + 1;
                if(k + 1 > max) max = k + 1;
            }
        }
        for(int z = j + 1;z < len;z ++){
            if(lvl[z] < lvl[j])break;
            else if(lvl[z] == lvl[j]){
                lvl[z] = k + 1;
                if(k + 1 > max) max = k+ 1;
            }
        }

    }
    for(int i = 0;i <= max;i ++){
       for(int j = 0;j < len;j ++){
        if(lvl[j] == i){
            cout << Mid[j];
        }
       }
    }
    cout << endl;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        go();
    }
}                                 