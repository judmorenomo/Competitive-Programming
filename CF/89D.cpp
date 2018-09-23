#include<bits/stdc++.h>
using namespace std;
int n1, n2, k1, k2;
const long long MOD = 100000000;
long long dp[110][110][20][2];

long long go(int foot, int hors, int cantAnt, int type){
	if(dp[foot][hors][cantAnt][type] != -1)return dp[foot][hors][cantAnt][type];
	if(foot == 0 && hors == 0)return 1;
	long long ans = 0;
	if(foot > 0){
		if(type == 2){
			ans = (ans + go(foot-1, hors, 1, 1));
		}else if(cantAnt+1 <= k1){
			ans = (ans + go(foot-1, hors, cantAnt+1, 1));
		}
		ans = ans % MOD;
	}
	if(hors > 0){
		if(type == 1){
			ans = (ans + go(foot, hors-1, 1, 2));
		}else if(cantAnt+1 <= k2){
			ans = (ans + go(foot, hors-1, cantAnt+1, 2));
		}
		ans = ans % MOD;
	}
	return dp[foot][hors][cantAnt][type] = ans;
}

int main(){
	scanf("%d %d %d %d", &n1, &n2, &k1, &k2);
	memset(dp, -1, sizeof dp);
	printf("%lld\n", go(n1, n2, 0, 0));
}