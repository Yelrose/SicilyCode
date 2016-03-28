
// Problem#: 5295
// Submission#: 1319695
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <string>
using namespace std;

string sen[100000];
int length;

int main(){
    string n;
   //    Let me ask you two questions. What is the answer to life? What is the answer to the universe?
    bool what = false;
    bool begin = false;
    //int first = 0;
    while(cin >> n){
        if(n == "What"){
            what = true;
        }
        else if(n == "is" && what == true){
            what = false;
            begin = true;
            sen[0] = "Forty-two is";
            length = 1;
            //first = 0;
        }
        else if(n == "is?" && what == true){
            what = false;
            begin = false;
                cout <<  "Forty-two is." << endl;
        }
        else if(n[n.length() - 1] == '?' && begin){
            n[n.length() - 1] = '.';
            what =false;
            begin = false;
            sen[length ++] = n;
            for(int i = 0;i < length;i ++){
                if(i > 0)cout << " ";
                cout << sen[i];
            }
            cout << endl;
        }
        else if(begin){
            int zzz = n.length() -1;
            if(n[zzz] == '.' || n[zzz] == '!'){
                begin = false;
                what = false;
                length = 0;
            }
            else sen[length ++] = n;

        }
    }
}                                 