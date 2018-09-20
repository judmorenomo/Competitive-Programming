#include<bits/stdc++.h>
using namespace std;
int depth[100001];
vector<vector<int> > graf;

void dfs(int u, int p){
	depth[p]++;
	for(int i = 0; i < graf[u].size(); i++){
		dfs(graf[u][i], p+1);
	}
}
int main(){
	int n;
	memset(depth, 0, sizeof depth);		
	scanf("%d", &n);
	graf.assign(n, vector<int>());
	for(int i = 1; i <= n-1; i++){
		int val;
		scanf("%d", &val);
		val--;
		graf[val].push_back(i);
	}
	dfs(0, 0);
	int ans = 0;
	for(int i = 0; i < n; i++){
		ans += depth[i]%2;
	}
	printf("%d\n", ans);
}