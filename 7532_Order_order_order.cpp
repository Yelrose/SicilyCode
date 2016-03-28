
// Problem#: 7532
// Submission#: 1951195
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>
using namespace std;
long long maxk[500100];
map<long long ,int> minMalAi;
long long miniAi_Bi;
long long sumf = 0;
bool first = true;
int cx = 0;
int countf = 1;
const long long inf = 0x7fffffffffffffff;
struct fuck{
    long long A;
    long long B;
}X[500100];
bool cmp(const fuck A,const fuck B){
    return A.B < B.B;
}
int main(){
    int n;
    scanf("%d",&n);
    miniAi_Bi =inf;
    for(int i = 0;i < n;i ++){
        scanf("%lld%lld",&X[i].A,&X[i].B);

        minMalAi[X[i].A] ++;
    }
    sort(X,X + n,cmp);
    for(int i = 0;i < n;i ++){
        if(i == 0)maxk[i] = X[i].B;
        else maxk[i] = maxk[i - 1] + X[i].B;
    }
    for(int i = 0;i < n;i ++){
        if(miniAi_Bi > (X[i].A - X[i].B)){
            miniAi_Bi = X[i].A - X[i].B;
        }
        minMalAi[X[i].A]--;
        if(minMalAi[X[i].A] == 0){
            minMalAi.erase(X[i].A);
        }
        //cout << miniAi_Bi.size() << " " << minMalAi.size() << endl;
        if(minMalAi.empty()){
            maxk[i] = maxk[i] + miniAi_Bi;
        }
        else{
            maxk[i] = maxk[i] + min(miniAi_Bi,- X[i].B + minMalAi.begin()->first);

        }
    }
    for(int i = 0;i < n;i ++){
        printf("%lld\n",maxk[i]);
    }
}                                 