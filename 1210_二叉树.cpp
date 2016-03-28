
// Problem#: 1210
// Submission#: 1624071
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 6213
// Submission#: 1623818
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

char a[30];
char b[30];
long long pow(int i,int count){
    if(count == 0)return 1;
    int sum = 1;
    for(int j = 0;j < count;j ++){
        sum *= i;
    }
    return sum;
}
int main(){
    cin >> a;
    int len = strlen(a);
    for(int i = strlen(a) - 1;i >= 0;i --){
        cin >> b[i];
    }
    b[len] = '0';
    int count = 0;
    for(int i = 0;i < len;i ++){
        int j = 0;
        while(a[i] != b[j]){
            j ++;
        }
        if(a[i + 1] == b[j + 1])count ++;
    }

    cout << pow(2,count);
}                                 