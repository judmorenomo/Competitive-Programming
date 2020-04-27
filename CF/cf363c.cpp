#include<bits/stdc++.h>
using namespace std;

vector<int> vals;
int dp[110][3];

int go(int pos, int last){
	if(pos == vals.size())return 0;
	if(dp[pos][last] != -1)return dp[pos][last];
	int ans = 1 + go(pos+1, 0);	
	if(vals[pos] == 1){
		if(last != 1)ans = min(ans, go(pos+1, 1));
	}else if(vals[pos] == 2){
		if(last != 2)ans = min(ans, go(pos+1, 2));
	}else if(vals[pos] == 3){
		if(last != 1)ans = min(ans, go(pos+1, 1));
		if(last != 2)ans = min(ans, go(pos+1, 2));
	}
	return dp[pos][last] = ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		vals.push_back(x);
	}
	memset(dp, -1, sizeof dp);
	cout << go(0, 0)<<'\n';
}
