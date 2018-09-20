#include<bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int n, k;
long long dp[2010][2010];
long long go(int pos, int num){	
	if(pos == k-1) return 1;	
	if(dp[pos][num] != -1)return dp[pos][num];		
	long long ans = 0;
	for(int i = num; i <= n; i += num){
		if(i %  num == 0){
			ans = (ans + go(pos+1, i)) % MOD;
		}
	}
	return dp[pos][num] = ans;
}
int main(){
	memset(dp, -1, sizeof dp);
	scanf("%d %d", &n, &k);
	long long ans = 0;	
	for(int i = 1; i <= n; i++){
		ans = (ans + go(0, i)) % MOD;
	}
	printf("%lld\n", ans);
}