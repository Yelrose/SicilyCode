
// Problem#: 6038
// Submission#: 1529358
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 6038
// Submission#: 1527866
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <queue>
using namespace std;
bool exitf[2000000];
long long a[20];
long long b[20];
long long m;
int n;
long long s;
struct Node{
    long long sum;
    int tim;
};
queue<Node> all;
Node temp;
Node temp1;
int main(){
    cin >> m >> n >> s;

    for(int i = 0;i < n;i ++){
        cin >> a[i] >> b[i];
    }
    temp.sum = s;
    temp.tim = 0;
    all.push(temp);
    exitf[s] = 1;
    while(!all.empty()){
        temp = all.front();
        exitf[temp.sum] = 1;
        all.pop();
        for(int i = 0;i < n;i ++){
            long long s1 = (temp.sum * a[i] + b[i]) % m;
            if(s1 == 0){
                cout << temp.tim + 1 << endl;
                return 0;
            }
            else if(!exitf[s1]){
                exitf[s1] = 1;

                temp1.sum = s1;
                temp1.tim = temp.tim +1;
                all.push(temp1);
            }
        }
    }
    cout << "-1" << endl;

}                                 