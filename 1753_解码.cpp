
// Problem#: 1753
// Submission#: 1602235
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;
string a;
int main(){
    while(cin >> a && a != "XXX"){
        int num = 0;
        char last;
        for(int i = 0;i < a.length();i ++){
            if(a[i] >= '0' && a[i] <= '9'){
                num *= 10;
                num += a[i] - '0';
            }
            else {
                for(int j = 1;j < num;j ++){
                    cout << last;
                }
                cout << a[i];
                last = a[i];
                num = 0;
            }
        }
        for(int j = 1;j < num;j ++){
                    cout << last;
        }

        num = 0;
        cout << endl;
    }
}                                 