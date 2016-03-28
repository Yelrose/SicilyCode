
// Problem#: 7143
// Submission#: 2899518
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
using namespace std;
char buff[40];
int main() {
	int T;
	scanf("%d",&T);
	while(T --) {
		int n;
		scanf("%d%s",&n,buff);
		int len = n;
		int tx,ty,bx,by;
		tx = ty = 0;
		bx = by = ((1 << n) - 1);
		for(int i = 0;i < len;i ++) {
			int ax,ay;
			n --;
			ax = ay = (1<< n);
			switch(buff[i]) {
				case '0': {
					bx -=ax;
					by -= ay;
					break;
				}
				case '1': {
					ty += ax;
					bx -= ax;
					break;
				}	
				case '2' : {
					tx += ax;
					by -= ay;
					break;
				}		
				case '3' :{
					tx += ax;
					ty += ay;
					break;
				}	
			}
			
		}
		printf("%d %d\n",bx,by );
	}
}                                 