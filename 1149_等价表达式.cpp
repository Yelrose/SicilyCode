
// Problem#: 1149
// Submission#: 1841767
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <map>
using namespace std;

stack<long long > opernum;
stack<char > oper;

const int prio[7][7] = {{0,0,0,0,1,1,1},{0,0,0,0,1,1,1},{1,1,0,0,1,1,1},{1,1,1,0,1,1,1},{1,1,1,1,1,1,1},{0,0,0,0,0,0,1},{0,0,0,0,0,0,1}};
int op(char a){
    switch(a){
        case '+':return 0;
        case '-':return 1;
        case '*':return 2;
        case '^':return 3;
        case '(':return 4;
        case ')':return 5;
        case '#':return 6;
        case '\0':return 6;
    }
}
map<string ,char> select;

void gocalc(){
    int o = op(oper.top());
    oper.pop();
    long long a = opernum.top();
    opernum.pop();
    long long b = opernum.top();
    opernum.pop();

    switch(o){
        case 0:opernum.push(a + b);break;
        case 1:opernum.push(b - a);break;
        case 2:opernum.push(a * b);break;
        case 3:{long long s = 1;
        for(int i = 1;i <= a;i ++){
            s *= b;
        }
        opernum.push(s);
            break;
        }
    }

}

long long cacl(string t,long long x){
    oper.push('#');
    long long tmp = 0;
    for(int i = 0;i <= t.size();i ++){

        if(t[i] == 'a')opernum.push(x);
        else if(t[i] == ' '){
            if(tmp > 0){
                opernum.push(tmp);
                tmp = 0;
            }
        }
        else if(t[i] >= '0' && t[i] <= '9'){
            tmp *= 10;
            tmp += (t[i] - '0');
        }
        else {
            if(tmp > 0){
                opernum.push(tmp);
                tmp = 0;
            }
            while(prio[op(t[i])][op(oper.top())] == 0){
                //cout << opernum.size() << endl;
                //cout << t[i] << " " << oper.top() << endl;
                if(oper.top() == '('){
                   if(t[i] == ')')oper.pop();
                  break;
                }gocalc();
                //cout << opernum.size() << endl;

            }
            if(t[i] == '\0' || t[i] == ')'){

            }
            else {
                oper.push(t[i]);
            }

        }
    }
    long long nu = opernum.top();
    opernum.pop();
    return nu;
}
queue<string > operation;
int main(){
    string k;
    getline(cin,k);
    int n;
    cin >> n;
    string tmp;
    getline(cin,tmp);
    for(int i = 0;i < n;i ++){
        getline(cin,tmp);
        operation.push(tmp);
        select[tmp] = 'A' + i;
    }
    operation.push("end");

    for(long long i = 1;i <= 100;i ++){
        long long re = cacl(k,i);
        while(!oper.empty()){
            oper.pop();
        }
        while(operation.front() != "end"){
            string tmp = operation.front();
            operation.pop();
            //cout << tmp << endl;
            long long ca = cacl(tmp,i);
            if(ca == re)operation.push(tmp);


        }
        operation.pop();
        operation.push("end");
    }
    while(operation.front() != "end"){
            string tmp = operation.front();
            operation.pop();
          cout << select[tmp];


    }
    cout << endl;
}                                 