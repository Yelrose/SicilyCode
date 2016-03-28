
// Problem#: 2013
// Submission#: 1812643
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
using namespace std;
long long owe;
long long money[100001];
int main(){
    int n;
    owe = 0;
    cin >> n;
    long long tot = 0;
    int owei = -1;
    int countf = 0;
    for(int i = 0;i < n;i ++){
        countf ++;
      
        cin >> money[i];
        if(money[i] < 0){
            owe -= money[i];
            if(owei == -1){
                owei = i;
            }
            if(tot >= owe && owe != 0){
                
                tot -= owe;
                countf += 2 * (i - owei);
                owei = -1;
                owe = 0;

            }

        }
        else {
            tot += money[i];
            if(tot > owe && owe != 0){
                tot -= owe;
                countf += 2 * (i - owei);
                owei = -1;
                owe = 0;

            }
        }

    }
    cout << countf << endl;
}                                 