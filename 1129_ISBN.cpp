
// Problem#: 1129
// Submission#: 1602187
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;

char all[12] = "0123456789X";
string a;
int main(){
    while(cin >> a){
        int in = 10;
        int sum = 0;
        for(int i = 0;i < a.length();i ++){
            if(a[i] >= '0' && a[i] <= '9'){
                sum += in * (a[i] - '0');
                in --;
            }
        }
        int plus = 0;
        while((sum + plus) % 11 != 0){
            plus ++;
        }
        cout << a << '-' << all[plus] << endl;
    }

}                                 