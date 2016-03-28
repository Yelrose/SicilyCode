
// Problem#: 10393
// Submission#: 2776300
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

string all[50010];
string zuixiao[50010];
string zuida[50010];
string l[50010];
string r[50010];
bool cmp(const char a,const char b){
    return a > b;
}
char buff[20];
int main() {
    int N;
    scanf("%d",&N);
    for(int i = 0;i < N;i ++) {
        scanf("%s",buff);
        all[i] = buff;
        sort(all[i].begin(),all[i].end());
        zuixiao[i] = all[i];
        l[i] = all[i];
        sort(all[i].begin(),all[i].end(),cmp);
        zuida[i] = all[i];
        r[i] = zuida[i];
    }
    sort(zuixiao ,zuixiao + N);
    sort(zuida, zuida + N);
    for(int i = 0;i < N;i ++) {
        string ll = l[i];
        int posl = lower_bound(zuida,zuida + N,ll) - zuida + 1;
        string rr = r[i];
        int posr = lower_bound(zuixiao,zuixiao + N,rr) - zuixiao + 1;
        if(rr > ll){
            posr --;
        }
        printf("%d %d\n",posl,posr);
    }
}                                 