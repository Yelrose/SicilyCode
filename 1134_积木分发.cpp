
// Problem#: 1134
// Submission#: 1414922
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
using namespace std;

struct Ji{
    int have;
    int need;

}All[10001];

bool cmp(const Ji & a,const Ji & b){
    return (a.need != b.need)? a.need < b.need : a.have > b.have;
}

int main(){
    int n,m;
    while(cin >> n >> m && n + m != 0){
        for(int i = 0;i < n;i ++){
            cin >> All[i].have >> All[i].need;
        }
        sort(All,All + n,cmp);
        long long sum = m;
        bool flag = true;
        for(int i = 0;i < n;i ++){
            if(sum >= All[i].need){
                sum += All[i].have;
            }
            else {
                flag = false;
                break;
            }
        }
        if(flag)cout << "YES" << endl;
        else cout << "NO" << endl;
    }


}                                 