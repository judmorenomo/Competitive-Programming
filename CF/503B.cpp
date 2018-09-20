#include<bits/stdc++.h>
using namespace std;
vector<int> graf[1010];
int res[1010];
bool vis[1010];
int ans = -1;

void dfs(int u){
	vis[u] = 1;
	for(int i = 0; i < graf[u].size(); i++){
		int v = graf[u][i];
		if(vis[v] == 1){
			ans = v;
			return;
		}else{
			dfs(v);
		}
	}
	return;
}


int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		val--;
		graf[i].push_back(val);
	}

	for(int i = 0; i < n; i++){
		memset(vis, 0, sizeof vis);
		dfs(i);
		res[i] = ans;
	}		
	for(int i = 0; i < n; i++){
		printf("%d ", res[i]+1);		
	}
	puts("");
}