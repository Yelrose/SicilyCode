
// Problem#: 2504
// Submission#: 2897579
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
using namespace std;

int n,m;
int L[500001];
int S[500001];
const int md = 10007;
int getAns() {
	int l =  S[1];
	int r = S[n];
	while(l < r) {
		int mid = (l+r) >> 1;
		int count = 0;
		int k = 0;
		int sta = 0;
		for(int i = 1;i <= n;i ++) {
			k += L[i];
			if(k > mid) {
				count ++;
				k = L[i];
				if(k > mid) {
					sta = 1;
					break;
				}
			}
		}
		
		if(sta == 1 || count > m) {
			l = mid+1;
		}
		else {
			r = mid;
		}
	}
	return (l + r) / 2;	
}

int dp[50010][2];
int ans;

int dpf() {
	int sumf = 0;
	for(int i = 1;i <= n;i ++) {
		int t = (S[i] > ans)?0:1;
		dp[i][0] = dp[i - 1][0] + t;
	//	cout << dp[i][0] << " ";
	}
//	cout << endl;
	sumf += (dp[n][0] - dp[n - 1][0]) % md;
	for(int i = 1;i <= m;i ++) {
		int j = 0;
		for(int k = 1;k <= n;k ++) {
			if(k <= i) {
				dp[k][i % 2] = 0;
				continue;
			}
			while(S[k] - S[j] > ans) {
				j ++;
			}
			//cout << j << " " << k << endl;
			int t;
			if(j - 1 > i - 1) {
				t = dp[k - 1][(i + 1)% 2] - dp[j - 1][(i + 1) % 2];
				
			}
			else {
				t = dp[k - 1][(i + 1)% 2];
				
			}
			t =  (t+ md) % md;
			//cout << k << " divide into " << i << " " << t << endl;
			dp[k][i % 2] =  (t + dp[k - 1][i % 2]) % md; 
		}	
		sumf += (dp[n][i % 2] - dp[n - 1][i % 2] + md) % md;
		sumf %= md;
	}
	return sumf;
}


int main() {
	scanf("%d%d",&n,&m);
	for(int i = 1 ;i <= n;i ++) {
		scanf("%d",&L[i]);
		S[i]  = L[i] + S[i - 1];
	} 
	
	ans=  getAns();
	cout << ans  << " " << dpf()<< endl;
	return 0;
	
}                                 