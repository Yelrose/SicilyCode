
// Problem#: 1932
// Submission#: 1304736
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <stack>
using namespace std;

stack<int > k;
int di[200001];

void go(){
    while(!k.empty()){
        k.pop();

    }
    int n;
    cin >> n;
    for(int i = 0;i < n;i ++){
        int a,b;
        cin >> a >> b;
        di[a] = b;
        di[b] = a;
    }
    for(int i = 1;i <= 2* n;i ++){
        if(k.size() == 0){
            k.push(i);
        }
        else {
            if(di[i] == k.top()){
                k.pop();
            }
            else k.push(i);
        }
    }
    if(k.empty())cout << "Yes" << endl;
    else cout << "No" << endl;

}


int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i ++)
        go();


}                                 