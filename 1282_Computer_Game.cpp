
// Problem#: 1282
// Submission#: 1543963
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int next[100000];
int p[100000];
int c[1000000];
int n,m;
void Next(){
    next[0] = -1;
    int k = -1;
    for(int i = 1;i < n;i ++){
        while(k != -1 && p[i] != p[k + 1]){
            k = next[k];
        }
        if(p[i] == p[k + 1]){
            k ++;
        }
        next[i] = k;
    }

}

void Match(){
    int i = 0;
    int k = -1;
    while(i < m){
        while(c[i] != p[k + 1] && k != -1){
            k = next[k];
        }
        if(c[i] == p[k + 1]){
            i ++;
            k ++;
            if(k == n - 1){
                cout << i - n << endl;
                return;
            }
        }
        else i ++;

    }
    cout << "no solution" << endl;
}

int main(){
    while(scanf("%d",&n) != EOF){
        for(int i = 0;i < n;i ++){
            scanf("%d",&p[i]);
        }
        scanf("%d",&m);
        for(int i = 0;i < m;i ++){
            scanf("%d",&c[i]);
        }
        Next();
        Match();
    }

}                                 