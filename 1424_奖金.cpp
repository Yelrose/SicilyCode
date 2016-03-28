
// Problem#: 1424
// Submission#: 1841186
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 6660
// Submission#: 1731707
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n,m;

vector<int > vet[10001];
int money[10001];
queue<int > bfs;
int rudu[10001];
int main(){
    cin >>n >> m;
    for(int i = 0;i < m;i ++){
        int a,b;
        cin >> a >> b;
        vet[b].push_back(a);
        rudu[a] ++;
    }
    for(int i = 1;i <= n;i ++){
        if(rudu[i] == 0){
            bfs.push(i);
            money[i] = 100;
        }
    }
    while(!bfs.empty()){
        int tmp = bfs.front();
        bfs.pop();
        for(int i = 0;i < vet[tmp].size();i ++){
            rudu[vet[tmp][i]] --;
            if(rudu[vet[tmp][i]] < 0) {
                cout << "Poor Xed" << endl;
                return 0;
            }
            if(rudu[vet[tmp][i]] == 0)bfs.push(vet[tmp][i]);
            if(money[vet[tmp][i]] <= money[tmp]){
                money[vet[tmp][i]] = money[tmp] + 1;
            }

        }
    }
    for(int i = 1;i <= n;i ++){
        if(rudu[i] > 0){
            cout << "Poor Xed" << endl;
            return 0;
        }
    }
    int tot = 0;
    for(int i = 1;i <= n;i ++){
        tot += money[i];
    }
    cout << tot << endl;
}                                 