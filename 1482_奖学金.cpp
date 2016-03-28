
// Problem#: 1482
// Submission#: 1602955
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
using namespace std;

struct info{
        int id;
        int tot;
        int chi;
}All[100000];
bool cmp(const info & a,const info & b){
    if(a.tot != b.tot){
        return a.tot > b.tot;
    }
    else if(a.chi != b.chi ){
        return a.chi > b.chi;
    }
    else return a.id < b.id;
}

void go(int n){
    for(int i = 0;i < n;i ++){
        int chi,math,eng;
        cin >> chi >> math >> eng;
        int sum = chi + math + eng;
        All[i].chi = chi;
        All[i].tot = sum;
        All[i].id = i + 1;
    }
    sort(All,All + n,cmp);
    for(int i = 0;i < 5;i ++){
        cout << All[i].id << " " << All[i].tot << endl;
    }
}

int main(){
    int n;
    bool first = false;
    while(cin >> n){
        if(first ++)cout << endl;
        go(n);
    }
}                                 