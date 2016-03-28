
// Problem#: 7974
// Submission#: 2039043
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <vector>

using namespace std;
vector<int > all;
int l,r;
int d;
int flag;
int R(){
    d = 1 - d;
}
void D(){
    if(d == 0){
       l ++;
    }
    else r --;
}


int main(){
    int T;
    ios::sync_with_stdio(0);
    cin >> T;
    while(T --){
        d = 0;


        all.clear();
        string p;
        cin >> p;
        int n;
        cin >> n;
        l = 0;
        r = n - 1;
        char ch;

        cin >> ch;
        int t;
        for(int i = 0;i < n;i ++){
            cin >> t >> ch;
            all.push_back(t);
        }
        if(n == 0)cin >> ch;
        for(int i = 0;i < p.size();i ++){
            if(p[i] == 'R'){
                R();
            }
            else if(p[i] == 'D'){
                D();
            }
        }
        if(l-1 > r)cout << "error" << endl;
        else {
            cout << "[";
            if(d==0)
            for(int i =l ;i <=r;i ++){
                if(i == l);//cout << '[';
                else cout << ',';
                cout << all[i];
            }
            else if(d == 1){
            for(int i =r ;i >=l;i --){
                if(i == r);//cout << '[';
                else cout << ',';
                cout << all[i];
                }
            }
            cout << ']' << endl;
        }
    }

}                                 