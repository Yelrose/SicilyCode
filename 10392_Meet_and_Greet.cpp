
// Problem#: 10392
// Submission#: 2776287
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
using namespace std;

int b[1000000];
int e[1000000];


int main() {
    int B,E;
    ios::sync_with_stdio(0);
    cin >> B >> E;
    int pos = 0;
    for(int i = 0;i < B;i ++) {
        char ch;
        int t;
        cin >> t >> ch;
        if(ch == 'R') {
             if(pos == 0){
                pos ++;
            }
           for(int j = pos;j < pos + t;j ++){
               if(j == 0)b[j] = 0;
               else b[j] = b[j - 1] + 1;
           }
           pos += t;
        }
        else {
             if(pos == 0){
                pos ++;
            }
            for(int j = pos;j < pos + t;j ++){
               if(j == 0)b[j] = 0;
               else b[j] = b[j - 1] - 1;
           }
           pos += t;
        }
    }
    int maxpos = pos;
    int maxposb = pos;
    pos = 0;
    for(int i = 0;i < E;i ++) {
        char ch;
        int t;
        cin >> t >> ch;
        if(ch == 'R') {
            if(pos == 0){
                pos ++;
            }
           for(int j = pos;j < pos + t;j ++){
               if(j == 0)e[j] = 0;
               else e[j] = e[j - 1] + 1;
           }
           pos += t;
        }
        else {
            if(pos == 0) pos ++;
            for(int j = pos;j < pos + t;j ++){
               if(j == 0)e[j] = 0;
               else e[j] = e[j - 1] - 1;
           }
           pos += t;
        }
    }
    maxpos = max(maxpos,pos);
    int maxpose = pos;
    int countf = 0;
    bool apart = false;
    for(int i = 0;i < maxpos;i ++) {
        if(i >= maxposb) {
            b[i] = b[i - 1];
        }
        if(i >= maxpose) {
            e[i] = e[i - 1];
        }
        if(b[i] == e[i] && apart == true){
            countf ++;
            apart = false;
        }
        else if(b[i] != e[i]) {
            apart = true;
        }
    }
    printf("%d\n",countf);
    return 0;
}                                 