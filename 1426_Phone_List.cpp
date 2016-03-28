
// Problem#: 1426
// Submission#: 1841435
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstring>
using namespace std;


struct trie{
    int ch[100100][10];
    int val[100100];
    int size;
    trie(){
        size = 1;
        memset(ch[0],0,sizeof(ch[0]));
        memset(val,0,sizeof(val));
    }
    void intial(){
        size = 1;
        memset(ch[0],0,sizeof(ch[0]));
        memset(val,0,sizeof(val));
    }
    bool insert(string tmp){
        int t = 0;
        for(int i = 0;i < tmp.size();i ++){
            int cur = tmp[i] - '0';
            if(!ch[t][cur]){
                ch[t][cur] = size;
                memset(ch[size],0,sizeof(ch[size]));
                size ++;

            }
            t = ch[t][cur];
            if(val[t] == 1)return false;

        }
        val[t]= 1;
        for(int i = 0;i < 10;i ++){
            if(ch[t][i] > 0)return false;
        }
        return true;
    }
}a;

int main(){
    int T;
    cin >> T;
    while(T --){
        int n;
        cin >> n;
        bool flag = true;
        a.intial();
        for(int i = 0;i < n;i ++){
            string tmp;
            cin >> tmp;
            if(flag){
                flag = a.insert(tmp);
            }
        }
        if(flag)cout <<     "YES" << endl;
        else cout << "NO" << endl;
    }

}                                 