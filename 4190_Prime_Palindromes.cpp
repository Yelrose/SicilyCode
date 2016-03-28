
// Problem#: 4190
// Submission#: 2199652
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 8585
// Submission#: 2199632
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

bool p[10010];
vector<int > prime;
vector<int > all;
bool judge(int a){
    for(int i = 2;i <= sqrt(a);i ++){
        if(a %  i == 0)return false;
    }
    string t;
    while(a > 0){
        char ch = a %10 +'0';
        a/= 10;
        t = ch + t;

    }
    for(int i = 0;i < t.size();i ++){
        if(t[i] != t[t.size() - i - 1])return false;
    }
    return true;
}

string flip(string a){
    string tmp = "";
    for(int i = 0;i < a.size();i ++){
        tmp = a[i]+ tmp;
    }
    return tmp;
}

int main(){
    /*for(int i = 2;i <= 10000;i ++){
        if(p[i] == 1)continue;
        else {
            prime.push_back(i);
            for(int j =i + i;j <= 10000;j += i){
                p[j] = 1;
            }
        }
    }*/
    for(int i = 1;i <= 9999;i ++){
        string tmp = "";
        int j = i;
        while( j > 0){
            char ch = j % 10 + '0';
            tmp = ch + tmp;
            j /= 10;
        }
        string num1 = tmp + flip(tmp);
        string num2 = tmp + flip(string(tmp,0,tmp.size() - 1));

        if(judge(atoi(num1.c_str()))){
            all.push_back(atoi(num1.c_str()));
        }
         if(judge(atoi(num2.c_str()))){
           all.push_back(atoi(num2.c_str()));

        }
    }
    sort(all.begin(),all.end());
    int a,b;
    while(cin >> a >> b && !(a == 0&& b == 0)){
        for(int i = 0;i < all.size();i ++){
            if(all[i] >= a && all[i] <= b)cout << all[i] << endl;
        }
    }
}                                 