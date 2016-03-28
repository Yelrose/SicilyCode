
// Problem#: 4873
// Submission#: 1239416
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
#include <cstring>
#define PER 0.05
using namespace std;

long double all_vote;
struct Data{
    char city;
    long double vote;
}All[150];

bool cmp(Data  a,Data  b){
    if(a.vote == b.vote)return a.city < b.city;
    return a.vote > b.vote;
}
bool cmp2(Data a, Data b){
    return a.city < b.city;
}

int big[30];
Data XX[10];

int main(){
    memset(big,0,sizeof(big));
    cin >> all_vote;
    all_vote *= PER;
    int n;
    cin >> n;
    int count = 0;;
    for(int i = 0;i < n;i ++){
        char city;long double vote;
        cin >> city >> vote;
        if(vote  >= all_vote){
            big[city - 'A'] = 1;
            for(int j = 1;j <= 14;j ++){
                All[count].city = city;
                All[count].vote = vote / j;
                count ++;
            }
        }
    }
    sort(All,All + count,cmp);
    int count2 = 0;
    for(int i = 0;i < 30;i ++){
        if(big[i] == 1){
            XX[count2].city = (char)('A' + i);
            XX[count2].vote = 0;
            count2 ++;
        }
    }
    for(int i =0;i < 14;i ++){
        for(int j = 0;j < count2;j ++){
            if(XX[j].city == All[i].city){
                XX[j].vote ++;
                break;
            }
        }
    }
    sort(XX,XX + count2,cmp2);
    for(int i = 0;i < count2;i ++){
        cout << XX[i].city << " " << XX[i].vote << endl;
    }

}                                 