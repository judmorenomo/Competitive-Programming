#include<bits/stdc++.h>
using namespace std;
int arr[110], n, dp[100][5];

int go(int d, int ant){ // nada -> 0 contest -> 1 gym -> 2
	if(d == n) return 0;
	if(dp[d][ant] != -1) return dp[d][ant];
	int ans = 0;
	if(arr[d] == 1){
		ans = 1 + go(d+1, 0);
		return dp[d][ant] = ans;
	}
	if(arr[d] == 2){
		if(ant == 1){
			ans = 1 +go(d+1, 0);
		}else{
			ans = min(1 + go(d+1, 0), go(d+1, 1));
		}
		return dp[d][ant] = ans;
	}
	if(arr[d] == 3){
		if(ant == 2){
			ans = 1 + go(d+1, 0);
		}else{
			ans = min(1 + go(d+1, 0), go(d+1, 2));
		}
		return dp[d][ant] = ans;
	}

	if(ant == 0){
		ans = min(go(d+1, 1), go(d+1, 2));
		ans = min(ans, 1 + go(d+1, 0));
	}else if(ant == 1){
		ans = min(1 + go(d+1, 0), go(d+1, 2));
	}else{
		ans = min(1 + go(d+1, 0), go(d+1, 1));
	}
	return dp[d][ant] = ans;
}

int main(){
	memset(dp, -1, sizeof dp);
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		val++;
		arr[i] = val;
	}
	printf("%d\n", go(0, 0));
}