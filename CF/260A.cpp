#include<bits/stdc++.h>
using namespace std;
long long cont[100010], dp[100010];

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);		
		cont[val]++;
	}	
	dp[0] = 0;
	dp[1] = cont[1];
	for(int i = 2; i < 100005; i++){
		dp[i] = max(dp[i-1], dp[i-2] + (cont[i]*i));
	}	
	printf("%lld\n", dp[100000]);
}