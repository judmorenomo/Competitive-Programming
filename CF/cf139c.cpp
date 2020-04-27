#include<bits/stdc++.h>
using namespace std;

vector<int> contWhi;
int n, m, x, y;

int dp[1010][1010][2];

int go(int pos, int actW, int col){
	if(pos == contWhi.size()){
		if(actW < x)return INT_MAX / 100;
		return 0;
	}
	if(dp[pos][actW][col] != -1)return dp[pos][actW][col];
	int ans = INT_MAX, cost[2] = {contWhi[pos], n-contWhi[pos]};
	if(actW < x){
		ans = min(ans, cost[col] + go(pos+1, actW+1, col));		
	}else if(actW+1 <= y){
		ans = min(ans, cost[!col] + go(pos+1, 1, !col));
		ans = min(ans, cost[col] + go(pos+1, actW+1, col));
	}else {
		ans = min(ans, cost[!col] + go(pos+1, 1, !col));
	}
	return dp[pos][actW][col] = ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> x >> y;
	contWhi.assign(m, 0);
	memset(dp, -1, sizeof dp);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c; cin >> c;
			if(c == '.')contWhi[j]++;
		}
	}	
	cout << min(contWhi[0]+go(1, 1, 0), n-contWhi[0]+go(1, 1, 1))<<'\n';	
}
