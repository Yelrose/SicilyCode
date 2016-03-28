
// Problem#: 7765
// Submission#: 2900763
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstring>
using namespace std;
int a[4] = {0,2,3,1};
int a2[4] = {0,3,1,2};
int b[5] = {0,3,1,4,2};
int gouzao[1000100];
int vis[1000100];
bool check(int n) {
    memset(vis,0,sizeof(vis));
    for(int i = 2;i <= n - 1;i ++) {
        if(gouzao[i] > gouzao[i - 1] && gouzao[i] > gouzao[i + 1]) {

        }
        else if(gouzao[i] < gouzao[i - 1] && gouzao[i] < gouzao[i + 1]) {

        }
        else {
            cout << "Wa 1 ";
            return false;
        }
    }
    int t = 1;
    int count= 0;
    for(int i = 1;i <= n;i ++) {
        vis[gouzao[i]] ++;
        if(vis[gouzao[i]] > 1) {
            cout << "Wa2";
            return false;
        }
    }
    memset(vis,0,sizeof(vis));
    while(!vis[t]) {
        vis[t] = 1;
        count ++;
        t =  gouzao[t];
    }
    if(count == n)return true;
    else {
        cout << "Wa3 ";
        return false;
    }
}


int main() {

    int n;
    while(cin >> n && n != 0){
        if(n == 5) {
            gouzao[1] = 4;
            gouzao[2] = 5;
            gouzao[3] = 2;
            gouzao[4] = 3;
            gouzao[5] = 1;
        }
        else {
            int i = 1;
            int countf = 0;
            for(;(n - i + 1) % 4 > 0;i += 3) {
                countf ++;
            }
            i = 1;
            for(;(n - i+ 1) % 4 > 0;i += 3) {
                if(countf % 2 == 1) {
                    for(int j = 0;j < 3;j ++) {

                        gouzao[i+ j] =  a[j + 1] + i - 1;
                        if(j == 0 && i != 1) {
                            swap(gouzao[i + j],gouzao[i + j - 1]);
                        }
                        if(a[j + 1] == 3 && i + 3<= n) {
                            gouzao[i+ j] = i + 3;
                        }
                    }
                }
                else {
                    for(int j = 0;j < 3;j ++){
                        gouzao[i+ j] =  a2[j + 1] + i - 1;
                        if(a2[j + 1] == 1 && i != 1) {
                            gouzao[i + j] = i - 1;
                        }
                    }
                }
                countf --;
            }
            for(;i <= n;i += 4) {
                for(int j = 0;j < 4;j ++) {
                    gouzao[i+ j] =  b[j + 1] + i - 1;
                    if(b[j + 1] == 1&& i != 1) {
                        gouzao[i +j] = i - 1;
                    }
                    if(b[j + 1] == 4 && i + 4<= n) {
                        gouzao[i +j] = i + 4;

                    }
                }

            }
        }
        for(int i = 1;i <= n;i ++) {
            if(i > 1)cout << " ";
            cout <<gouzao[i];
        }
        cout << endl;
        /*if(!check(n)) {
            cout <<" WA" << n << endl;
        }
        else cout << "AC " << n << endl;
        */
    }
}                                 