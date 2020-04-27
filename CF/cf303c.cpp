#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int> > trees;

int dp[100010][2];

int go(int pos, int last){
	if(pos == trees.size())return 0;
	if(dp[pos][last] != -1)return dp[pos][last];
	int ans = go(pos+1, 0);
	int limLeft = trees[pos-1].first, limRig = (pos + 1 < trees.size() ? trees[pos+1].first : INT_MAX);
	if(last == 1)limLeft = trees[pos-1].first+trees[pos-1].second;
	if(trees[pos].first-trees[pos].second > limLeft)ans = max(ans, 1 + go(pos+1, 0));
	if(trees[pos].first+trees[pos].second < limRig)ans = max(ans, 1 + go(pos+1, 1));
	return dp[pos][last] = ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;	
	memset(dp, -1, sizeof dp);
	for(int i = 0; i < n; i++){
		int x, h;
		cin >> x >> h;
		trees.push_back({x, h});
	}	
	cout << 1 + go(1, 0)<<'\n';
}
