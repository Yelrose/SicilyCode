
// Problem#: 4874
// Submission#: 2179749
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
using namespace std;

struct cube{
    int up;
    int front;
    int right;
    cube(){
        up = 1;
        front = 2;
        right = 3;
    }
    void RollR(){
              int tmp = right;
        right = up;
        up = 7 - tmp;

    }
    void RollL(){
              int tmp = up;
        up = right;
        right = 7 - tmp;
    }
    void RollN(){
        int tmp = front;
        front = up;
        up = 7 - tmp;
    }
    bool Origin(){
        return (up == 1 && front == 2 && right == 3);
    }

};
int main(){
    long long  R;
    long long  C;
    long long  sumr = 0;
    cin >> R >> C;
    cube s;
    long long  i;
    for(i = 0;i < R;i ++){
        bool fuck = false;
        for(long long  j = 0;j < C;j ++){
                if(i % 2 ==0 && j == 0 && i != 0 && s.Origin()){
                    //cout << s.up << " " << s.right << " " << s.front << " " << sumr << endl;
                        fuck = true;
                        break;
                }
                else {
                    sumr +=s.up;
                    if(i %2 == 0 && j != C - 1){
                        s.RollR();

                    }
                    else if(j == C - 1){
                        s.RollN();
                    }
                    else if(i %  2 == 1 && j != C - 1){
                        s.RollL();
                    }
                }
        }
        if(fuck)break;
    }
    long long sumf = (R / i) * sumr;

    R = R%i;
   // cout << R << endl;
    for(i = 0;i < R;i ++){
        for(int j = 0;j < C;j ++){
                    sumf +=s.up;
                    if(i %2 == 0 && j != C - 1){
                        s.RollR();

                    }
                    else if(j == C - 1){
                        s.RollN();
                    }
                    else if(i %  2 == 1 && j != C - 1){
                        s.RollL();
                    }


        }
    }
    cout << sumf << endl;
    return 0;
}                                 