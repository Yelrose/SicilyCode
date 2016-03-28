
// Problem#: 1687
// Submission#: 2121510
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,k;
int array[200][200];
const int md = 2007;
int main(){
    while(cin >> n >> k){
        if(k == 0){
            cout << 1 << endl;
            continue;
        }
        memset(array,0,sizeof(array));
        array[0][0] = 1;
        int countf = 0;
        for(int i = 1;i <= n;i ++){
            array[i][0] = 1;
            for(int j = 1;j <= min(k,i);j ++){
                array[i][j] = (array[i-1][j] +(array[i - 1][j]* j %md)+ ((i- 1 - (j - 1))*array[i - 1][j - 1])%md)%md;
            }
        }
        cout << array[n][k] << endl;
    }
}                                 