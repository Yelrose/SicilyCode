
// Problem#: 1002
// Submission#: 1276367
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstring>

using namespace std;

int prime[10000];
int array[10000];
int used[10000];
int n,m,d;
bool findone = false;

bool judge2(int k){

        int sum = 0;

        for(int j = 0;j < d && k - j >= 0;j ++){
            sum += array[k - j];

            if(j >= 1){

                if(prime[sum] )return false;
            }
        }


    return true;
}

void go(int a,int b){
    array[b] = a;
    used[a] = 1;

    bool fuck = judge2(b);
        if(!fuck)
        {
            used[a] = 0;
            return;
        }
       if((b == m - n) && fuck){
            for(int i = 0;i <= b;i ++){
                if(i)cout << ",";
                cout << array[i];
            }
            cout << endl;
            findone = true;
            used[a] = 0;
            return;
        }

    for(int i = n;i <= m;i ++){
        if(used[i] == 0){
            go(i,b + 1);
            if(findone){
                used[a] = 0;
                return;
            }
        }
    }

    used[a] = 0;
    if(findone)return;

}
int main(){

    prime[0] = 0;
    prime[1] = 0;
    for(int i = 2;i <= 10000;i ++){
        if(prime[i] == 0){

            for(int j = 2;j * i<= 10000;j ++){
                prime[i * j] = 1;
            }
        }
    }
    for(int i = 2;i <= 10000;i ++){
        if(prime[i] == 0)prime[i] = 1;
        else prime[i] = 0;
    }

    while(cin >> n >> m >> d && n + m + d > 0){
        findone = false;
        for(int i = n;i <= m;i ++){

            go(i,0);
            if(findone)break;
        }
        if(!findone)cout << "No anti-prime sequence exists." << endl;
    }


}                                 