
// Problem#: 1033
// Submission#: 1766455
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 1033
// Submission#: 1517439
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstring>
using namespace std;
int n,m;
long long sqr[3000010];
bool blockup[3000010];
bool blockleft[3000010];

int trans(int x,int y){

    return x * (m + 1) + y;
}
int main(){
    while(cin >> n >> m && n * m != 0){
        n ++;
        m ++;
        memset(sqr,0,sizeof(sqr));
        memset(blockup,0,sizeof(blockup));
        memset(blockleft,0,sizeof(blockleft));
        int nn;
        cin >> nn;
        for(int i = 0;i < nn;i ++){
            int x1,a,y1,b;
            cin >> x1 >> y1 >> a >> b;
            for(int x = x1;x < x1 + a - 1;x ++){
                for(int y = y1 - 1;y < y1 + b - 1;y ++){

                    blockleft[trans(x,y)] = true;
                }
            }
            for(int x = x1 - 1;x < x1 - 1 + a;x ++){

                for(int y = y1;y < y1 + b -1;y++){

                    blockup[trans(x,y)] = true;
                }

            }
        }

        for(int x = 0;x < n;x ++){
            for(int y = 0;y < m;y ++){
                if(x == 0 || y == 0){
                    sqr[trans(x,y)] = 1;

                }
                //cout << trans(x,y) << endl;
                if(!blockleft[trans(x,y)]){
                    sqr[trans(x,y + 1)] += sqr[trans(x,y)];
                }
                //else cout << "shit" << endl;
                if(!blockup[trans(x,y)]){

                    sqr[trans(x + 1,y)] += sqr[trans(x,y)];
                }
                //else cout << "fuck" << endl;

                //cout << sqr[trans(x,y)] << " ";

            }
            //cout << endl;

        }
       /* for(int i = 0;i <= n;i ++){
            for(int j = 0;j <= m;j ++){

                cout << sqr[trans(i,j)] << " ";
            }
            cout << endl;
        }

        for(int i = 0;i <= n;i ++){
            for(int j = 0;j <= m;j ++){

                cout << trans(i,j) << " ";
            }
            cout << endl;
        }*/
        cout << sqr[trans(n - 1,m - 1)] << endl;
    }
}                                 