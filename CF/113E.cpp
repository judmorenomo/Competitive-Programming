#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int dp[2][5];
int main(){		
	int n;
	scanf("%d", &n);
	int flag = 0;
	dp[0][0] = dp[0][1] = dp[0][2] = 1;	
	for(int i = 2; i <= n; i++){		
		flag = (flag + 1)% 2;		
		for(int j = 0; j <= 3; j++){
			dp[flag][j] = 0;
			for(int k = 0; k <= 3; k++){
				if(j != k){					
					dp[flag][j] = dp[flag][j] + dp[(flag+1)%2][k];
					if(dp[flag][j] > MOD)dp[flag][j] -= MOD;
				}
			}
		}			
	}			
	printf("%d\n", dp[flag][3]);
}