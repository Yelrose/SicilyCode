
// Problem#: 1899
// Submission#: 2897799
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <map>
#include <set>
using namespace std;

int abs(int k){
    if(k < 0)return -k;
    return k;
}
set<pair<int ,int >  > all;
int main() {
    int T;
    cin >> T;
    while(T -- ){
    
    int n;
    cin >> n;
        all.clear();
        for(int i = 0;i < n;i ++) {
            int a,b;
            cin >> a >> b;
            all.insert(pair<int ,int > (a,b));
            
        }
        int countf = 0;
        for(set<pair<int ,int > >::iterator it = all.begin();it != all.end();it ++) {
            for(set<pair<int ,int > >::iterator it2 = all.begin();it2 != all.end();it2 ++) {
                if(it == it2)continue;
                if(it -> first == it2 ->first) {
                    int d = abs(it -> second - it2->second);
                    //cout << it -> first << " " << it -> second  << " " << it2-> first << " " << it2 ->second << endl;
                    pair<int ,int > a = pair<int ,int > (it->first + d,it->second);
                    //cout << a.first << " " << a.second << endl;
                    pair<int ,int > b = pair<int ,int > (it2 -> first + d,it2 -> second);
                    //cout << b.first << " " << b.second << endl;
                    //cout << all.count(a) << " " << all.count(b) << endl;
                    if(all.count(a) && all.count(b)) {
                        
                        countf ++;
                    } 
                    
                }
                
            }
            
        }
        countf /= 2;
        cout << countf << endl;
        
    
    
    }
}                                 