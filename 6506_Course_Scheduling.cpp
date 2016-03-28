
// Problem#: 6506
// Submission#: 2900730
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
#include <map>
#include <cctype>
#include <set>
#include <cstdio>
using namespace std;

struct card{
    string name;
    string name2;
    string course;
    card(string a,string b,string c) : name(a)  , name2(b) , course(c) {
    }
    card() {
    }

};

void get(card & a) {
    cin >> a.name >> a.name2 >> a.course;
}

bool operator < (const card a,const card b) {
    if(a.name == b.name) {
        if(a.name2 == b.name2) {
            return a.course < b.course;
        }
        else return a.name2 < b.name2;
        return a.name2 < b.name2;
    }
    else return a.name < b.name;
}
set<card > all;
map<string ,int > ans;
int main() {
    //freopen("D.1.dat","r",stdin);
   // freopen("log.txt","w",stdout);
    int n;
    cin >> n;
    for(int i = 0;i < n;i ++) {
        card t;
        get(t);
        if(all.count(t)) {
        }
        else {
            ans[t.course] ++;
            all.insert(t);
        }
    }
    for(map<string , int>::iterator it =  ans.begin(); it != ans.end();it ++) {
        cout << it-> first  << " " << it ->second << endl;
    }

}                                 