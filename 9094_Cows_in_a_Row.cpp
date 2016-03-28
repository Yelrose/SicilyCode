
// Problem#: 9094
// Submission#: 2333287
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int countf[1000010];
int a[1010];
int main(){
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for(int i = 0;i  <n ;i ++){
        cin >> a[i];
    }
    int maxf = 0;
    for(int i = 0;i < n;i ++ ){
        if(i >= 1 ){
            if(a[i] == a[i - 1]){
                countf[a[i]] ++;
                maxf = max(maxf,countf[a[i]]);
            }
            else {
                countf[a[i]] = 1;
                maxf = max(maxf,countf[a[i]]);
            }
        }
        else {
                countf[a[i]] = 1;
                maxf = max(maxf,countf[a[i]]);
        }

    }
    for(int i = 0 ;i < n;i ++){
        int e = a[i];

        for(int j = 0;j < n;j ++){
            if(a[j] == e){
                continue;
            }
            if(j >= 1){
                int t = a[j];
                int in = j - 1;
                while(a[in] == e&& in >= 0){
                    in --;
                }
                if(in == -1 || a[in] != a[j]){
                    countf[a[j]] = 1;
                    maxf = max(maxf,countf[a[j]]);

                }
                else {
                    countf[a[j]] ++;
                    maxf = max(maxf,countf[a[j]]);

                }
            }

            else {
                countf[a[j]] = 1;
                maxf = max(maxf,countf[a[j]]);
            }


        }
    }
    cout << maxf << endl;
}                                 