
// Problem#: 1938
// Submission#: 2897607
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 1194
// Submission#: 1411010
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
using namespace std;

string Friend[20001];
string notSend[20001];

int main(){
    int T;
    cin >> T;
    while(T --) {
          int n,m;
          cin >> n >> m;
          for(int i = 0;i < n;i ++){
            cin >> Friend[i];
            for(int j = 0;j < Friend[i].size();j ++){
                Friend[i][j] = tolower(Friend[i][j]);
            }
        }
         for(int i = 0;i < m;i ++){
            cin >> notSend[i];
            for(int j = 0;j < notSend[i].size();j ++){
                notSend[i][j] = tolower(notSend[i][j]);
            }
        }
        sort(notSend,notSend + m);
        int count = n;
        for(int i = 0;i < n;i ++){
            int l = 0;
            int r = m - 1;
            while(l <= r){
                if(Friend[i] > notSend[(l + r) / 2]){
                    l = (l + r) / 2 + 1;
                }
                else if(Friend[i] < notSend[(l + r) / 2]){
                    r = (l + r) / 2 - 1;
                }
                else if(Friend[i] == notSend[(l + r) / 2]){
                    count --;
                    break;
                }

            }
        }
        cout << count << endl;
            
        
        
        
    }
  
  
}                                 