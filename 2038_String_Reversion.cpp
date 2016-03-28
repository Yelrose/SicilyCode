
// Problem#: 2038
// Submission#: 2897945
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
using namespace std;


void print(string t) {
	int pos = -1;
	for(int i = 0;i < t.size();i ++) {
		if(t[i] == '_')pos =i;
		
	}
	if(pos == -1) {
		for(int i = t.size() - 1;i >= 0;i --) {
			cout << t[i];
		}
	}
	else {
		print(string(t,0,pos));
		cout << "_";
		print(string(t,pos+1,t.size() - 1));
		
	}
	
}

int main() {
	
	int T;
	cin >> T;
	while(T --) {
		string k;
		cin >> k;
		print(k);
		cout << endl;
	}
}                                 