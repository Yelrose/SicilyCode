
// Problem#: 8537
// Submission#: 2900831
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <map>
#include <cctype>
using namespace std;
string p;
typedef map<string ,int > list;
void M(list & ele, string word) ;
int strtoint(string t) {
    if(t == "")return 1;
    int tot = 0;
    for(int i = 0;i < t.size();i ++) {
        tot *= 10;
        tot += t[i] - '0';
    }
    return tot;
}

void S(list & ele,string word) {
    //cout << "S " << word << endl;
    if(word[0] == '(') {
        string nxt = "";
        for(int i = 1;i < word.size() - 1;i ++) {
            nxt += word[i];
        }
        M(ele,nxt);
    }
    else {
        ele[word] ++;
    }
}

void G(list & ele,string word) {
    //cout << "G " << word << endl;
    list tmp;
    string num = "";
    string s = "";
    int i = word.size() - 1;
    for(;i >= 0;i --) {
        if(isdigit(word[i])) {
            num = word[i] + num;
        }
        else break;
    }
    for(;i >= 0;i --) {
        s = word[i] + s;
    }
    //cout << num << " " << s << endl;
    S(tmp,s);
    int n =  strtoint(num);
    for(list::iterator it =  tmp.begin();it != tmp.end();it ++) {
        ele[it -> first] += it->second * n;
    }

}


void M(list & ele, string word) {
    //cout << "M " << word<< endl;
    string t = "";
    int count = 0;
    int leftk = 0;
    for(int i = 0;i < word.size();i ++) {
        if(word[i] == '(') {
            if(leftk == 0 && t != "") {
                M(ele,t);
                count ++;
                t = "";
            }
            t+= word[i];
            leftk ++;
        }
        else if(word[i] == ')') {
            t += word[i];
            leftk --;
        }
        else if(isupper(word[i])) {
            if(leftk == 0 && t != "") {
                M(ele,t);
                count ++;
                t = "";
            }
            t += word[i];
        }
        else {
            t += word[i];
        }
    }
    //cout << "shit " << count  << " word " << word << " " << t << endl;
    if(t != "" && count > 0) {
        M(ele,t);
    }
    else if(t != "" && count == 0) {
        G(ele,t);
    }
}


int main() {

    while(getline(cin,p)) {
        list ele;
        M(ele,p);
        bool first = false;
        for(list::iterator it = ele.begin();it != ele.end();it ++) {
            if(first ++)cout <<"+";
            if(it->second > 1)cout << it -> second;
            cout <<it->first;
        }
        cout << endl;
    }
    return 0;
}                                 