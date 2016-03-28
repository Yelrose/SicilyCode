
// Problem#: 10479
// Submission#: 2754254
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int pos;
int minf;
int maxf;
typedef pair<int ,int > edge;
vector<edge > all;
bool cmp(const edge a,const edge b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    else {
        return a.first < b.first;
    }
}
int main(){
    pos = 0;
    int N;
    minf = maxf = 0;
    scanf("%d",&N);
    for(int i = 0;i < N;i ++){
        int t;
        char c;
        cin >> t >> c;
        edge tmp;
        if(c == 'R'){
            tmp = edge(pos,min(maxf,pos+t));
            all.push_back(tmp);
            maxf =  max(maxf,pos+t);
            pos += t;
        }
        else if(c == 'L'){
            tmp = edge(max(pos - t,minf),pos);
            all.push_back(tmp);
            minf =  min(minf,pos - t);
            pos -= t;
        }
    }
    sort(all.begin(),all.end(),cmp);
    int ll,lr;
    ll = 0;
    lr = 0;
    int sumf = 0;
    for(int i = 0;i < all.size();i ++){
        if(i == 0){
            ll = all[i].first;
            lr = all[i].second;
        }
        else {
            if(all[i].first <= lr && all[i].first >= ll){

                lr = max(lr,all[i].second);
            }
            else {
                sumf += lr - ll;
                ll =  all[i].first;
                lr = all[i].second;
            }
        }
    }
    sumf += lr - ll;
    cout << sumf << endl;
}                                 