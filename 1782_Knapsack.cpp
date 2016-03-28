
// Problem#: 1782
// Submission#: 1312525
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 5012
// Submission#: 1312257
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstring>
using namespace std;
int d[1001][10001];
int ca[1001];
int max(int & a,int & b){
    return (a > b) ? a : b;
}
void go(){
     
     int num,c;
     cin >> num >> c;
     for(int i = 0;i < num;i ++)
             cin >> ca[i];
     for(int i = 0;i <= c;i ++){
          d[0][i] = 0;
          if(i >= ca[0])d[0][i] = ca[0];           
     }
     for(int i = 1;i < num;i ++){
             for(int j = 0;j <= c;j ++){
                     d[i][j] = 0;
                     if(j < ca[i])d[i][j] = d[i - 1][j];
                     else d[i][j] = max(d[i - 1][j],(d[i - 1][j - ca[i]] + ca[i]));
             }
     }
    
     cout << d[num - 1][c] << endl;
}


int main(){
    int T;
    cin >> T;
    for(int i = 0;i < T;i ++)
            go();
            
    //system("pause");

}                                 