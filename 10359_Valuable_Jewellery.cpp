
// Problem#: 10359
// Submission#: 2745911
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef pair<int ,int >  J;
J all[300000];
map<int ,int > C;
map<int ,int >::iterator index;
bool cmp (const J a,const J b) {
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i = 0;i < n;i ++){
        scanf("%d%d",&all[i].first,&all[i].second);
    }
    sort(all,all+ n,cmp);
    for(int i = 0;i < k;i ++){
        int t;
        scanf("%d",&t);
        C[t] ++;
    }
    long long value = 0;
    for(int i = n - 1;i >= 0;i --){
        int v = all[i].second;
        int m = all[i].first;
        index = C.lower_bound(m);
        if(index != C.end()){
            index -> second --;
            if(index -> second == 0){
                map<int ,int >::iterator in2 = index;
                in2 ++;
                C.erase(index,in2);

            }
            value += v;
        }

    }
    printf("%lld\n",value);
    return 0;
}                                 