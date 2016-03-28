
// Problem#: 7905
// Submission#: 2023959
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <queue>
#include <iomanip>
#include <stack>
using namespace std;
stack <int > out;
struct Lo{
    int left;
    int known;
    double rate;
    Lo(int a,int b,double c):left(a),known(b),rate(c){

    }
};
typedef vector <Lo > state;
bool first;
double dfs(state T){
    if(T.size() == 0)return 1;
    int left = T.size();
    int chose = 1 << left;
    int chose2 = 1 << left;
    double maxf = 0;

    for(int ii = 0;ii < chose ;ii ++){
        double res = 0;
        for(int i = 1;i < chose;i ++){
            double w = 1;
            state tmp;
            int k = i;
            int kk = ii;
            for(int j = 0 ;j < left;j ++,k /= 2,kk /= 2){
                if(k % 2 == 1){
                    if(kk % 2== 1 &&T[j].known >= 1){
                        w *= T[j].rate / T[j].known;
                    }
                    else if(kk % 2 == 1){
                            w = 0;
                    }
                    else w *= (1.0 - T[j].rate) / (T[j].left - T[j].known);
                }
                else if(kk%2== 1&&T[j].known >= 1){
                    w *= (1 - T[j].rate / T[j].known);
                    if(T[j].left - 1 == 0)w = 0;
                    else tmp.push_back(Lo(T[j].left - 1,T[j].known - 1,(T[j].known - 1)*(T[j].rate / T[j].known)/(1 - T[j].rate/T[j].known)));

                }
                else if(kk % 2 == 1)w = 0;
                else if(kk % 2 == 0&& T[j].left > T[j].known){
                    w *= (1 - (1.0 - T[j].rate) / (T[j].left - T[j].known));
                    if(T[j].left - 1 == 0)w =0;
                    else tmp.push_back(Lo(T[j].left- 1,T[j].known,T[j].rate/(1 -(1.0 - T[j].rate) / (T[j].left - T[j].known) )));
                }
                else {
                    w = 0;
                }
            }
            if(w == 0);
            else  w *= dfs(tmp);
            res += w;
            //cout << res << endl;
        }
        if(res > maxf)maxf = res;
    }
    return maxf;
}


int main(){
    int n;
    while(scanf("%d",&n)&& n != 0){
        state k;
        for(int i = 0;i < n;i ++){
            int a,b;
            double c;
            scanf("%d%d%lf",&a,&b,&c);
            k.push_back(Lo(a,b,c));

        }
           bool first = false;
           double res = dfs(k);
            int fu = res * 10000;
            if(fu % 10  >= 5 ){
                fu /= 10;
                fu += 1;
            }
            else {
                fu/= 10;

            }
            bool firs = false;
            int damn = 1;
            while(damn < 5){
                int t = fu % 10;
                if(t == 0 && !firs ){
                }
                else {
                    firs ++;
                        out.push(t);
                }
                fu /= 10;
                damn ++;
            }

            if(out.empty()){
                printf("0\n");
            }
            else {
                printf("%d",out.top());
                bool f= false;
                out.pop();
                while(!out.empty()){
                    int tmp = out.top();
                    out.pop();
                    if(!f){
                        f ++;
                        printf(".");
                    }
                    printf("%d",tmp);
                }
                printf("\n");
            }
    }

}                                 