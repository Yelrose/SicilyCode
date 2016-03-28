
// Problem#: 4960
// Submission#: 1265444
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <stack>
using namespace std;
long double k1 ;
string all[301];

stack<long double > suan;

bool go(int n,int z){
    k1 = z;
    string temp;
    for(int i = 0;i < n;i ++){
        temp = all[i];

        if(temp == "x"){
            suan.push(k1);

        }
        else if(temp == "sin"){
            long double t = suan.top();
            suan.pop();
            suan.push(sin(t));

        }
        else if(temp == "cos"){
            long double t = suan.top();
            suan.pop();
            suan.push(cos(t));

        }
        else if(temp == "tan"){
            long double t = suan.top();
            suan.pop();
            suan.push(tan(t));

        }
        else if(temp == "+"){
            long double a = suan.top();
            suan.pop();
            long double b = suan.top();
            suan.pop();
            suan.push(a + b);

        }
        else if(temp == "*"){
            long double a = suan.top();
            suan.pop();
            long double b = suan.top();
            suan.pop();
            suan.push(a * b);

        }
        else if(temp == "-"){
            long double a = suan.top();
            suan.pop();
            long double b = suan.top();
            suan.pop();
            suan.push(b - a);

        }

    }

    if(abs(suan.top() - 0) <= 10e-10 ){
            return true;
    }
    else return false;
}


int main(){
    int n;
    while(cin >> n && n != 0){
        while(!suan.empty()){
            suan.pop();
        }
        long double k;
        bool ca = true;
        for(int i = 0;i < n;i ++){
            cin >> all[i];
        }
        for(double  i = 1;i <= 10;i ++){
            while(!suan.empty()){
                suan.pop();
            }
            k = 3.1415926 /  (i + 1) * (i);
            ca = go(n,k);

            if(!ca)break;
        }
        if(ca)cout << "Identity" << endl;
        else cout << "Not an identity" << endl;


    }

}                                 