
// Problem#: 1443
// Submission#: 1792084
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

int p[101];
queue<int >fuck;
int countf[10];
int maxf;

int main(){
    int T;
    scanf("%d",&T);
    while(T --){
        int n,pos;
        memset(countf,0,sizeof(countf));
        while(!fuck.empty())fuck.pop();
        maxf = 0;
        scanf("%d%d",&n,&pos);
        //cout << maxf << endl;
        for(int i = 0;i < n;i ++){
            scanf("%d",&p[i]);
            if(p[i] > maxf)maxf = p[i];//cout << "fuck" ; cout << p[i] <<endl;}
            //cout << maxf << endl;
            countf[p[i]] ++;
            //cout << "countf++"<<maxf << endl;
            fuck.push(i);
            //cout << "fuck++" << maxf << endl;
            //cout << i << " " << maxf << endl;
        }
        for(int i = 0;i < n;i ++){
           // cout << p[i] << " ";
        }
        //cout << endl;
        int counta = 1;
        //cout << maxf << endl;
        while(!fuck.empty()){
            int tmp = fuck.front();
            //cout << maxi << endl;
            fuck.pop();
            if(p[tmp] == maxf){
                if(tmp == pos){
                    printf("%d\n",counta);
                    break;
                }
                else {
                    countf[p[tmp]] --;
                    if(countf[p[tmp]] == 0){
                        int k = p[tmp] -1;
                        while(countf[k] == 0 && k > 0)k --;
                        maxf = k;
                    }
                    counta ++;
                }
            }
            else {
                fuck.push(tmp);
            }
        }
    }
}                                 