
// Problem#: 7147
// Submission#: 1838668
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long p[21][201];

void intial(){
    p[0][0] = 1;
    for(int i = 1;i <= 20;i ++){
        for(int j = 0;j <= 9;j ++){
            for(int k = 0;k <= 200;k ++){
                    if(k - j>= 0) p[i][k] += p[i - 1][k- j];
            }
        }
    }
}
long long  re[201];
long long re1[201];

void go(string t){
    int shift = 0;
    for(int i = 0;i < t.size();i ++){
        int cur = t[i] -'0';
        int wei = t.size() - i - 1;
        for(int j = 0;j < cur;j ++){
            for(int k = 0;k <= 200;k ++){
                if(k - j - shift >= 0)re[k] += p[wei][k - j - shift];
            }
        }
        shift += cur;
    }

}

void go1(string t){

    int shift = 0;
    for(int i = 0;i < t.size();i ++){
        int cur = t[i] -'0';
        int wei = t.size() - i - 1;
        for(int j = 0;j < cur;j ++){
            for(int k = 0;k <= 200;k ++){
                if(k - j - shift >= 0)re1[k] += p[wei][k - j - shift];
            }
        }
        shift += cur;
    }
    re1[shift] ++;
}

int main(){
    //long long k = 0x7fffffffffffffff;
    //cout << k << endl;
    intial();
    string  a,b;
    int c;
    int case1= 0;
    while(cin >> a >> b >> c &&  c > 0){
        case1 ++;
        memset(re,0,sizeof(re));
        memset(re1,0,sizeof(re1));
        go(a);
        go1(b);
        long long  countf = 0;
        for(int i = 0;i <= 200;i ++){
            re1[i] -= re[i];
            if(i % c == 0){
                countf += re1[i];
            }
        }

        cout << "Case "<< case1<< ": "<<countf << endl;

    }

}                                 