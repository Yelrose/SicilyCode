
// Problem#: 5123
// Submission#: 2899774
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef unsigned long long LL;
const LL md = 19930211;
LL x[2000];
LL H[2000];
char buff[2000];
string line;
map<LL ,int > tim;
int main() {
    x[1] = md;
    for(int i = 2;i <= 2000;i ++) {
        x[i] = md * x[i - 1];
    }
    while(getline(cin,line) && line != "") {
        int sz = 0;
        tim.clear();
        for(int i = 0;i < line.size();i ++) {
            if(line[i] != ' ' ) {
                buff[sz ++] = line[i];
            }
        }
        H[sz] = 0;
        for(int i = sz - 1;i >= 0;i --) {
            H[i] =  md * H[i + 1] + buff[i] - 'A' + 1;
            
        }
        for(int len = 1;len <= sz;len ++) {
            int maxf = 0;
            tim.clear();
            for(int i = 0;i + len <= sz;i ++) {
                LL ha =  H[i] - x[len] * H[i + len];
                //cout << ha << endl;
                tim[ha] ++;
                maxf = max(maxf,tim[ha]);
            }
            if(maxf > 1) {
                cout << maxf << endl;
                
            }
            else {
                cout << endl;
                break;
            }
        }
        
    }
}                                 