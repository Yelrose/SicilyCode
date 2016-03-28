
// Problem#: 1133
// Submission#: 1597580
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <cstring>

using namespace std;
string a;
char out[10000];
bool word(char i){
    return ((i >= 'a' && i <= 'z') ||(i >= 'A' && i <= 'Z') || i == '-' || i == '_' || (i >= '0' && i <= '9' ));
}
int main(){
    while(getline(cin,a)){

        int index = 0;
        int goback = 0;
        bool at = false;
        for(int i = 0;i <= a.length();i ++){
            if(word(a[i])){
                out[index] = a[i];
                index ++;
            }
            else if(((!word(a[i]) && a[i] != '.')|| (a[i] == '.'&& out[index - 1] == '.')) && index > 0 && at){
                    while(!word(out[index - 1])){


                        index --;
                    }
                    bool flag = false;
                    for(int j = 0;j < index;j ++){

                        if(out[j] == '@')flag =true;
                    }
                    if(flag){

                        out[index] = '\0';
                        cout << out << endl;
                        i = goback;

                    }
                    at = false;
                    index = 0;



            }
            else if(a[i] == '@'){
                if(index == 0){
                    continue;
                }
                else {
                    out[index] = '@';
                    index ++;
                    goback = i;
                    at = true;
                }
            }
            else if(a[i] == '.'){
                if(index == 0){
                    continue;
                }
                else if(!word(out[index - 1])){
                    at = false;
                    index = 0;
                    continue;
                }

                out[index] ='.';
                index ++;

            }
            else {
                index = 0;
            }
        }
    }

}                                 