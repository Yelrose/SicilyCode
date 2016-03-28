
// Problem#: 4835
// Submission#: 1221583
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstring>

using namespace std;

char num[20][10];
bool inverse(string n){
    string k = n;
    int length = n.length();
    for(int i = 0;i < length;i ++){
        k[(length - i - 1)] = n[i];
    }
    k[length] = '\0';
    //cout << k << endl;
    return k == n;

}

void go(){
    char word[30];
    string temp = "";
    cin >> word;
    for(int i = 0;i < strlen(word);i ++){
        if(word[i] >= 'a' && word[i] <= 'z'){
            word[i] = word[i] - 'a' + 'A';
        }
    }
    //cout << word << endl;
    for(int i = 0;i < strlen(word);i ++){
        int k = 0; int kk = 0;
        for(int j = 2;j <= 9;j ++){
            bool a = false;
            for(int jj = 0;jj < strlen(num[j]);jj ++){
                if(num[j][jj] == word[i]){
                    k = j;
                    kk = jj;
                    a = true;
                    break;
                }

            }
            if(a) break;
        }


            string zzz = "0";
            zzz[0] += k;
            temp += zzz;

    }
    //cout << temp << endl;

    if(inverse(temp) == true){
        cout << "YES"<<endl;
        return;
    }
    cout << "NO" << endl;
    return;
}

int main(){
    strcpy(num[2],"ABC");
    strcpy(num[3],"DEF");
    strcpy(num[4],"GHI");
    strcpy(num[5],"JKL");
    strcpy(num[6],"MNO");
    strcpy(num[7],"PQRS");
    strcpy(num[8],"TUV");
    strcpy(num[9],"WXYZ");
    int T;
    cin >> T;
    for(int i = 0;i < T;i ++)
        go();
}                                 