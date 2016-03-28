
// Problem#: 1150
// Submission#: 3457105
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
string goal;
int N;
string operA(string t) {
    for(int i = 0;i < 4;i ++) {
        swap(t[i],t[i + 4]);
    }
    return t;
}

string operB(string t) {
    char a,b;
    a = t[3];
    b = t[7];
    for(int i = 3;i >= 1;i --){
        t[i] = t[i - 1];
        t[i + 4] = t[i + 4 - 1];
    }
    t[0] = a;
    t[4] = b;
    return t;
}

string operC(string t) {
    char a = t[1];
    t[1] = t[5];
    t[5] = t[6];
    t[6] = t[2];
    t[2] = a;
    return t;
}

bool dfs(string t,int st,string t2) {
   // cout << t << " " << st << " " <<t2<< endl;
    if(st > N) return false;
    if(t == goal) {
        cout << st << " " << t2 << endl;
        return true;
    }
    if(dfs(operA(t),st +1,t2+"A")) return true;
    if(dfs(operB(t),st+1,t2+"B"))return true;
    if(dfs(operC(t),st+1,t2+"C"))return true;
    return false;

}


int main() {

    while(cin >> N && N != -1) {
        string t= "";
        for(int i = 0;i < 8;i  ++) {
            char ch;
            cin  >> ch;
            t += ch;
        }
        goal = t;
        string t1 = "12348765";
       // cout << operB(t1) << endl;
        if(!dfs(t1,0,"")) {
            cout << "-1" << endl;
        }
    }

}                                 