#include<bits/stdc++.h>
using namespace std;
int dp[1010][1010];
string word;

int go(int l, int r){
	if(l == r)return 0;
	if(l+1 == r){
		if(word[l] == word[r])return 0;
		else return 1;
	}
	if(dp[l][r] != -1)return dp[l][r];
	if(word[l] == word[r])return dp[l][r] = go(l+1, r-1);		
	else return dp[l][r] = 1 + min(go(l+1, r), min(go(l, r-1), go(l+1, r-1)));;			
}
int main(){
	int t, cont = 1;
	scanf("%d", &t);
	while(t--){
		memset(dp, -1, sizeof dp);		
		cin >> word;
		int ans = go(0, word.size()-1);
		printf("Case %d: %d\n", cont++, ans);		
	}
	return 0;
}