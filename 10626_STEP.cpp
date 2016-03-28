
// Problem#: 10626
// Submission#: 2897932
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <set>
#include <cstdio>
#include <map>
using namespace std;

struct len {
    int l;
    len(int t):l(t){
        
    }
    len(){
        
    }
};

bool operator < (const len a, const len b) {
    return a.l > b.l;
}

set<pair<int ,int > > segment;
map<len ,int > maxlen;

void deleteSegmentlen(len t) {
    maxlen[t] --;
    if(maxlen[t] == 0){
        maxlen.erase(maxlen.find(t));
    }
}

void addSegmentlen(len t) {
    maxlen[t] ++;
}
void addSegment(int x,int y) {
    segment.insert(pair<int ,int >(x,y));
    addSegmentlen(len(y - x + 1));
}

void deleteSegment(set<pair<int ,int > >::iterator it) {
    deleteSegmentlen(it->second - it -> first + 1);
    segment.erase(it);
}

void deleteSegmentWithT(int t) {
    set<pair<int ,int > >::iterator it = segment.upper_bound(pair<int ,int > (t,t));
    if(it == segment.end())
        it --;
    else if(it -> first > t) {
        it --;
    }
    if(it->first < t && t < it -> second) {
        addSegment(it->first,t- 1);
        addSegment(t,t);
        addSegment(t+1,it ->second);
        deleteSegment(it);
    }
    else if(it -> first == it -> second){
        set<pair<int ,int > >::iterator nxt =  it;
        nxt ++;
        int beginx =  t;
        int endy = t;
        set<pair<int ,int > >::iterator last = it;
        if(last != segment.begin()) {
            last --;
            beginx = min(beginx,last ->first);
            deleteSegment(last);
        }
        if(nxt != segment.end()) {
            endy = max(endy,nxt ->second);
            deleteSegment(nxt);
        }
        deleteSegment(it);
        addSegment(beginx,endy);
        
    }
    else if(it -> first == t) {
        set<pair<int ,int > >::iterator last =  it;
        int beginx = t;
        int endy = it -> second;
        if(last != segment.begin()) {
            last --;
            beginx = min(beginx,last -> first); 
            deleteSegment(last);
        }
        deleteSegment(it);
        addSegment(beginx,t);
        addSegment(t + 1,endy);
        
    }
    else if(it -> second == t) {
        set<pair<int ,int > >::iterator  nxt = it;
        nxt ++;
        int beginx = it->first;
        int endy =  t;
        if(nxt != segment.end()) {
            endy = nxt->second;
            deleteSegment(nxt);
        }
        deleteSegment(it);
        addSegment(beginx,t - 1);
        addSegment(t,endy);
    }
}

void print(){
    for(set<pair<int ,int > >::iterator it = segment.begin();it != segment.end();it ++) {
        printf("(%d,%d) ",it->first,it->second);
    }
    puts("");
    
}

int main() {
    int N,Q;
    scanf("%d%d",&N,&Q);
    for(int i = 1;i <= N;i ++) {
        segment.insert(pair<int ,int > (i,i));
        maxlen[1] ++;
    }
    while(Q -- ) {
        int t;
        scanf("%d",&t);
        deleteSegmentWithT(t);
        
        
        printf("%d\n",*maxlen.begin());
        //print();
    }
    return 0; 
}                                 