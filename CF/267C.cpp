#include<bits/stdc++.h>
using namespace std;

vector<int> v;
long long dp[5010][5010];
long long sum[5010];

int main(){
	int n, m, k;	
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		if(i == 0){
			sum[0] = val;
		}else{
			sum[i] = val + sum[i-1];
		}
		v.push_back(val);
	}
	memset(dp, 0, sizeof dp);
	dp[m-1][1] = sum[m-1];		
	for(int i = m; i < n; i++){
		for(int j = 1; j <= k; j++){
			dp[i][j] = max(dp[i-1][j], dp[i-m][j-1] + sum[i]-sum[i-m]);
		}
	}
	printf("%lld\n", dp[n-1][k]);
}