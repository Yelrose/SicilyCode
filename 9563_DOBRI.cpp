
// Problem#: 9563
// Submission#: 2992566
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int exist[400010];

int array[100010];

int encode(int x) {
    return x + 200000;
}


int main() {
    int N;
    scanf("%d",&N);
    int countf = 0;
    for(int i = 0;i < N;i ++) {
        cin >> array[i];
    }
    exist[encode(array[0] + array[0])] ++;
    for(int i = 1;i < N;i ++) {
        for(int j = 0;j < i;j ++) {
            if(exist[encode(array[i] - array[j])]) {
                countf ++;
                break;
            }
        }
        
        for(int j = 0;j <= i;j ++) {
            exist[encode(array[i] + array[j])] ++;
        }
    }
    cout << countf << endl;
}                                 