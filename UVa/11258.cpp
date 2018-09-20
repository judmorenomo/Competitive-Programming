#include<bits/stdc++.h>
using namespace std;
#define lim 2147483647
int n;
string word;
long long dp[202];

long long go(int i){
	if(i == n)return 0;
	if(dp[i] != -1)return dp[i];
	long long ans = 0, sum = 0;
	for(int j = 1; j <= 10 && i+j <= n; j++){
		sum = sum*10 + (word[i+j-1]-'0');
		if(sum <= lim)ans = max(ans, sum + go(i+j));
	}
	return dp[i] = ans;
}


int main(){
	int num;
	scanf("%d", &num);
	while(num--){
		memset(dp, -1, sizeof dp);
		cin >> word;
		n = word.size();
		printf("%lld\n", go(0));
	}	
}