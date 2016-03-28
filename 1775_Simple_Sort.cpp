
// Problem#: 1775
// Submission#: 1603125
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
using namespace std;

struct Info{
    int num[100];
    int id;
}All[1000];
int n,m;
int prioty[100];

bool operator < (const Info & a,const Info & b){
    int max = prioty[0];
    int index = 0;
    for(int i = 0;i < m;i ++){
        if(prioty[i] < max){
            max = prioty[i];
            index = i;
        }
    }
    bool nolast = true;
    while(a.num[index] == b.num[index] && nolast){

        bool find = false;
        int ma;
        int in;
        for(int i = 0;i < m;i ++){
            if(!find && prioty[i] > max){
                ma = prioty[i];
                in = i;
                find = true;
            }
            else if(find && prioty[i] < ma && prioty[i] > max){
                ma = prioty[i];
                in = i;
            }
        }
        if(find){
            max= ma;
            index = in;
        }
        else nolast = false;

    }
    if(a.num[index] == b.num[index]) return a.id <b.id;
    return a.num[index] < b.num[index];
}

void go(){
    cin >> n >> m;
    for(int i = 0;i < n;i ++){
        All[i].id = i;
        for(int j =0;j < m;j ++){
            cin >> All[i].num[j];
        }
    }
    int q;
    cin >> q;
    for(int i =0 ;i <q ;i  ++){
        for(int j = 0;j < m;j ++)
            cin >> prioty[j];
        sort(All,All + n);

        bool first = false;
        for(int j = 0;j < n;j ++){
            if(first ++)cout <<" ";
            cout << All[j].id;
        }
        cout << endl;
    }

}

int main(){
    int T;
    cin >> T;
    while(T --){
        go();
    }
}                                 