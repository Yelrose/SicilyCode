
// Problem#: 1351
// Submission#: 1623077
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
using namespace std;

struct fuck{
    int a;
    int b;
}C[1000001];

bool cmp(const fuck & a,const fuck & b){
    return a.b < b.b;
}

int main(){
    int n,m;
    while(cin >> n >> m){
    for(int i = 0;i < n;i ++){
        C[i].a = i + 1;
        C[i].b =-1;
    }
    for(int i = 0;i < m;i ++){
        int t;
        cin >> t;
        C[t - 1].a = t;
        C[t - 1].b = i;
    }
    sort(C,C+ n,cmp);
    int countf = 0;
    for(int i = 0;i < n;i ++){
        if(C[i].b > -1)countf ++;
    }
    cout << countf << endl;
    if(countf == m)continue;
    bool first = false;
    for(int i = 0;i < n;i ++){
        if(C[i].b > -1){
            if(first ++)cout << " ";
            cout << C[i].a;
        }
    }
    cout << endl;
    }

}                                 