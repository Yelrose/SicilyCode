
// Problem#: 1052
// Submission#: 1518438
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;

int loop[20000];
int add[20000];
int n;
bool even(int a){
    return a % 2 == 0;
}
bool stop(){

    for(int i = 0;i < n - 1;i ++){

        if(loop[i] != loop[i + 1])return false;
    }
    return true;
}
int main(){

    while(cin >> n && n  != 0){
        for(int i = 0;i < n;i ++){
            cin >> loop[i];
        }
        int w,candy;
        w = 0;
        candy = 0;
        while(!stop()){
            w ++;
            for(int i = 0;i < n;i ++){
                loop[i] /= 2;
                if(i == 0){
                    add[n - 1] = loop[i];
                }
                else add[i - 1] = loop[i];
            }
            for(int i = 0;i < n;i ++){
                loop[i] += add[i];
                if(!even(loop[i])){
                    loop[i ] ++;

                }
            }
        }
        cout << w << " " << loop[0]<< endl;

    }


}                                 