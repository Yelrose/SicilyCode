
// Problem#: 10483
// Submission#: 2756622
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <map>
#include <set>
using namespace std;

int num[100010];
map<int ,int > countf;

multiset<int ,greater<int > > rank;

int main() {
    int N,K;
    scanf("%d%d",&N,&K);
    for(int i  = 0 ; i < N;i ++){
        scanf("%d",&num[i]);
    }
    int l,r;
    l = r = 0;
    int maxf = 0;
    while(l < N){
        while(countf.size() <= K + 1 && r < N){
            if(countf.count(num[r]) == 0 && countf.size() == K+ 1 ){
                break;
            }
            rank.erase(countf[num[r]]);
            countf[num[r]] ++;
            rank.insert(countf[num[r]]);
            r ++;
        }
        maxf = max(maxf,*rank.begin());

        rank.erase(countf[num[l]]);

        countf[num[l]] --;
        rank.insert(countf[num[l]]);
        if(countf[num[l]] == 0){
            countf.erase(num[l]);
        }
        l ++;
    }
    cout << maxf << endl;
    return 0;
}                                 