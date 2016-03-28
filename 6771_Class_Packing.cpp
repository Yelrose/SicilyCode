
// Problem#: 6771
// Submission#: 1759017
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 6771
// Submission#: 1754901
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
using namespace std;

int a[7] = {20,20,20,25,25,30,30};
int b[7];
int main(){
    while(1){
        bool fuck = false;
        for(int i = 0;i < 7;i ++){
            scanf("%d",&b[i]);
            if(b[i] > 0) fuck = true;
        }
        if(!fuck){
            break;
                cout << "fuck "<< endl;
        }
        int n = 0;
        for(int i = 0;i < 6;i ++){
            if(b[i] < 0)continue;
            int k = b[i] % a[i];
            int t = b[i] / a[i];
            if(k > 0){
                k -= a[i];
                t ++;
                b[i + 1] += k;
            }
            n += t;


        }
        if(b[6] > 0){
            int k = b[6] % a[6];
            int t = b[6] / a[6];
            if(k > 0){
                t ++;
            }
            n += t;
        }
        printf("%d\n",n);
    }

}                                 