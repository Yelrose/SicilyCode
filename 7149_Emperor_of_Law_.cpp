
// Problem#: 7149
// Submission#: 2899569
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
using namespace std;
long long ans[2010];
long long M[2010][2010];
long long K[2010];
long long re[4010];
long long dp[4010][2000];
const long long md = 1000000000 + 7;
long long x,y,q;
void extend_Eulid(long long  a,long long  b)
 {
     if(b == 0){
          x = 1;y = 0;q = a;
     }else{
         extend_Eulid(b,a%b);
         long long temp = x;
         x = y;
         y = temp - a/b*y;

     }
}
int main() {
   // freopen("test.in","r",stdin);
    //freopen("log.txt","w",stdout);
	int n,m;
	int maxloop = 0;
	for(int i = 1;i <= 4000;i ++) {
		long long t = i;
		extend_Eulid(t,md);
		while(x < 0) x += md;
		re[i] = x % md;
		//if( re[i] * i % md != 1)cout << "fukc"<< endl;
	}
	for(int i = 0;i < 2000;i ++) {
		for(int j = 0;j < 2000;j ++) {
			if(i == j){
				if(j == 0)M[i][j] = 1;
				else {
					M[i][j] = M[i][j - 1];
				}
				continue;
			}
			long long t =  i - j + md;

			t %= md;
			long long tmp;
			if(t <= 4000){
                tmp =  re[(int)t];
			}
			else {
                extend_Eulid(t,md);
                while(x < 0){ x += md;
                }
                tmp = x % md;
			}
			if(j == 0) {
				M[i][j] = tmp;
			}
			else {
				M[i][j] = (M[i][j - 1] * tmp)% md;
			}
		}
	}
	for(int i = 0;i <= 4000;i ++) {
        for(int j = 0;j < min(i,2000);j ++) {
            if(j== 0){
                dp[i][j] = (i - j);
            }
            else {
                dp[i][j] = (i - j) * dp[i][j - 1] % md;

            }
        }
	}
	//return 0;
	while(~scanf("%d%d",&n,&m))	 {
		if(n == 0 || m == 0)break;
		for(int i = 0;i < n;i ++) {
			scanf("%lld",&ans[i]);
		}
        for(int i = 0;i < n;i ++) {
            K[i] = ans[i] * M[i][n - 1]%md;
        }
		for(int i = n ;i < n+m;i ++) {
			if(i > n ) printf(" ");
			long long a = 0;
			long long head = 1;

			for(int j = 0;j < n;j ++) {
				a += (re[i - j] * K[j]) % md;
				a %= md;
			}
			a *= dp[i][n-1];
			a %= md;
			printf("%lld",a);
		}
		puts("");
	}

}                                 