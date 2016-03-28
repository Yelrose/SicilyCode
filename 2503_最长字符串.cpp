
// Problem#: 2503
// Submission#: 1294767
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;
int A[2][1000001];
int f;
int kuai(int a,int b){
    int k = 0;
    if(a % b > 0){
        k ++;
    }
        int kuaik = a / b + k;
    for(int i = 0;i< kuaik;i ++){
        if(a < b){

            A[f][i] = a;
            a -= a;
        }
        else {
            A[f][i] = b;
            a -= b;
        }
    }
    f ++;
    return kuaik;
}
int min(int a,int b){
    if(a < b)return a;
    return b;
}

int main(){
    int countA, countB, maxA, maxB;
    cin >> countA>>countB >> maxA >> maxB;
    if(maxA == 0 && maxB == 0){
        cout << '0' << endl;
        return 0;
    }
    else if(maxA == 0){
        cout << min(countB,maxB) << endl;
        return 0;
    }
    else if(maxB == 0){
        cout << min(countA,maxA) << endl;
        return 0;
    }
    int kuaiA;
    int kuaiB;
    kuaiA = kuai(countA,maxA);
    int kA = 0;
    int kB = 1;
    kuaiB = kuai(countB,maxB);
    bool change = false;
    if(kuaiA < kuaiB){
        int temp = kuaiA;

        kuaiA = kuaiB;
        kuaiB = temp;
        change = true;
        kA = 1;
        kB = 0;
    }
    int ktemp = kuaiB;
    int x = 0;
    while(ktemp < kuaiA - 1){
        if(x == kuaiB)break;
        if(A[kB][x] > 1){
            ktemp ++;
            A[kB][x] --;
        }
        else x ++;

    }
    int sum = countB;
    if(change){
        sum = countA;
    }
    for(int i = 0;i <= ktemp;i ++){
        sum += A[kA][i];
    }
    cout << sum << endl;


}                                 