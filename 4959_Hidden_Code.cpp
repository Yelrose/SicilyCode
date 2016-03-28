
// Problem#: 4959
// Submission#: 1270182
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstring>
using namespace std;


string C;
string P;


void go(int n){
    int kn = n;
    string all[kn];
    while(n --){
        cin >>  P >> C;
        string temp = "";
        bool yes = false;
        for(int k = 1;k <= P.length();k ++){
            string zz = "0";
            int z = (int ) C[k - 1] - P[k - 1];
            if(z < 0)z += 26;
            zz[0] =  'A' + (char)( z);
            //cout << zz << endl;
            temp += zz;
            bool right = true;
            for(int j = k;j < P.length();j ++){
                if((C[j] - 'A')!= (P[j] + C[j - k]) % 26){
                    right = false;
                    break;
                }
            }
            if(right){
                break;
            }
        }
        all[n] = temp;
        //cout  << all << endl;
    }
    int lengthf = 0;
    int what = 0;
    for(int i = 0;i < kn;i ++){
        if(all[i].length() > lengthf){
            lengthf = all[i].length();
            what = i;
        }
    }
    string ca = all[what];
    for(int i = 0;i < kn;i ++){
        for(int j = 0;j < all[i].length();j ++){
            if(all[i][j] != ca[j]){
                cout << "Impossible" << endl;
                return;
            }
        }
    }
    cout << ca << endl;

}


int main(){
    int n;
    while(cin >> n && n != 0){
        go(n);
    }
}                                 