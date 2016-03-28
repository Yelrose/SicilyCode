
// Problem#: 1003
// Submission#: 1276587
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;


queue<int > player[10];
int countf[10];
int num;
int last[10];


int countfc = 0;
bool allempty(){
    for(int i = 0;i < num;i ++){
        if(!player[i].empty())return false;
    }
    return true;
}
int casef = 1;

void go(){
    cin >> num;
    for(int i =0;i < num;i ++){
        countf[i] = 1;
        while(!player[i].empty()){
            player[i].pop();
        }

    }
    for(int i = 0;i < 52;i ++){
        int a;
        cin >> a;
        player[0].push(a);
    }
    while(!allempty() && countfc < 100){
        for(int i = 0;i < num;i ++){
            if(!player[i].empty() ){
                //cout << round[i] << "   xxx    " << i << endl;
                int k = player[i].front();
                //cout << k << "   countf" << countf[i] << endl;
                last[i] = k;
                player[i].pop();
                if(countf[i] == k && i + 1 < num){
                    player[i + 1].push(k);

                    countfc = 0;

                }
                else if(countf[i] == k && i == num - 1){
                   countfc = 0;
                }
               else{
                    player[i].push(k);
                    countfc ++;
                }
                countf[i] ++;
                if(countf[i] > 13) countf[i] = 1;
            }

        }

    }
    if(countfc >= 100){
         cout << "Case "  << casef << ": ";
            cout << "unwinnable" << endl;
            return;
    }
    cout << "Case "  << casef << ":";
    for(int i = 0;i < num;i ++){

        cout << " " << last[i];

    }
    cout << endl;
    return;
}


int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i ++){



        countfc = 0;
        go();
        casef ++;
    }

}                                 