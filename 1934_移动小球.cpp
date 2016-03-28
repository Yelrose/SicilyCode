
// Problem#: 1934
// Submission#: 1543352
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 6020
// Submission#: 1518904
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;

int l[500003];
int r[500003];

void move_l(int x,int y){
    r[l[x]] = r[x];
    l[r[x]] = l[x];
    r[x] = y;
    l[x] = l[y];
    r[l[y]] = x;
    l[y] = x;
}

void move_r(int x,int y){
    r[l[x]] = r[x];
    l[r[x]] = l[x];
    l[x] = y;
    r[x] = r[y];
    l[r[y]] = x;
    r[y] = x;

}

void go(){
    int n,m;
    cin >> n >> m;
    r[0] = 1;
    for(int i = 1;i <= n;i ++){
        l[i] = i - 1;
        r[i] = i + 1;
    }
    for(int i = 1;i <= m;i ++){
        int s,x,y;
        cin >> s >> x >> y;
        if(s == 1)move_l(x,y);
        else move_r(x,y);
    }
    int first = 0;
    for(int i = r[0];i != n + 1;i = r[i] ){
        
        cout << i<< " ";;
    }
    cout << endl;
}


int main(){
    int T;
    cin >> T;
    while(T --){
        go();
    }

}                                 