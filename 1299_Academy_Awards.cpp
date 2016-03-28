
// Problem#: 1299
// Submission#: 1770663
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
map<string ,int >zuijia;
string best;
int bestim;

int n;
int main(){
    while(cin >> n && n != 0){
        bestim = 0;
        zuijia.clear();
        for(int i = 0;i < n;i ++){
            string tmp;
            cin >> tmp;
            int m;
            cin >> m;
            for(int j = 0;j < m;j ++){
                cin >> tmp;
                zuijia[tmp] ++;
                if(zuijia[tmp] > bestim){
                    best =tmp;
                    bestim = zuijia[tmp];
                }
            }
        }
        cout << best << endl;
    }
}                                 