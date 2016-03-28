
// Problem#: 7904
// Submission#: 2023360
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 7904
// Submission#: 2022722
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <set>
#include <vector>

#include <stack>
using namespace std;
set<int > seq;
int counttt;

int array[4];

void dfs(vector<int > k){
    if(k.size() == 1){
        seq.insert(k[0]);
        return;
    }
    else {
        for(int i = 0;i < k.size();i ++){
            for(int j = 0;j < k.size();j ++){
                if(i != j){
                   for(int oper = 0;oper < 4;oper ++){
                    vector <int > tmp;
                    for(int z = 0;z < k.size();z ++){
                        if(z != i && z != j){
                            tmp.push_back(k[z]);
                            }

                    }

                    switch (oper){
                        case 0:tmp.push_back(k[i] + k[j]);break;
                        case 1:tmp.push_back(k[i]-k[j]);break;
                        case 2:tmp.push_back(k[i] * k[j]);break;
                        case 3:{
                            if(k[j]==0)continue;
                            if(k[i] % k[j] != 0)continue;
                            else tmp.push_back(k[i]/k[j]);break;
                        }

                    }
                    dfs(tmp);
                   }
                }
            }
        }

    }

}
vector<pair<int ,int > > all;
int main(){
    int ca = 1;
    while(cin >> array[0] >> array[1] >> array[2] >> array[3] && !(array[0]==0 &&array[1]==0 && array[2] == 0 && array[3] == 0)){
        seq.clear(); // counttt=0;
        dfs(vector<int > (array,array + 4));
        all.clear();
        int last = *seq.begin();
        int front = * seq.begin();



        for(set<int >::iterator it = seq.begin();it != seq.end();it ++ ){
            //cout << * it << endl;
            if(* it != front + 1){
                all.push_back(pair<int ,int >(last,front));
                last = *it;
                front = * it;
            }
            else front = * it;
        }
        all.push_back(pair<int ,int >(last,front));
        int maxs = 0;
        int pos;
        for(int i = 0;i < all.size();i ++){
            if(all[i].second - all[i].first >= maxs){
                maxs = all[i].second - all[i].first;
                pos = i;
            }

        }
        cout << "Case " << ca << ": " << all[pos].first << " to " << all[pos].second << endl;
        ca ++;
     }
}                                 