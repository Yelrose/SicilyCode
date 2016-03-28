
// Problem#: 1087
// Submission#: 1459970
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;

int win[1000001];

int main(){
    win[1] = 1;
    win[2] = 1;
    int a = win[1];
    int b = win[2];
    for(int i = 3;i <= 1000000;i ++){
        if(a == 1 && b == 1){
            win[i] = 0;
            a = b;
            b = win[i];
        }
        else {
            win[i] = 0;
            a = b;
            b = win[i];
        }
    }
    int k;
    while(cin >> k && k!= 0){
        if(win[k] == 1)cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
}                                 