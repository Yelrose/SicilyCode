
// Problem#: 10330
// Submission#: 2745305
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int cut = n;
    int cutn = n;
    n *= m;
    int count = 0;
    for(int i = 1;i <= n;i ++){
        if(i == cut && i % m != 0){
            count ++;

        }
        if(i == cut){
            cut += cutn;
        }

    }
    cout << count << endl;
}                                 