#include<bits/stdc++.h>
using namespace std;

vector<int> graf[1000010], ans;
vector<vector<int> > desde;
bool tomado[1000010], vivo[1000010];
int n, m;

void dfs(int u){
	if(u == n)return;
	if(!vivo[u])return dfs(u+1);

	vivo[u] = 0;
	for(int i = 0; i < graf[u].size(); i++){
		vivo[graf[u][i]] = 0;
	}
	dfs(u+1);
	bool yes = true;
	for(int i = 0; i < desde[u].size(); i++){
		int v = desde[u][i];
		yes &= !(tomado[v]);
	}
	if(yes){
		tomado[u] = 1;
		ans.push_back(u);
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		x--; y--;
		graf[x].push_back(y);
	}
	vector<int> nada;
	desde.assign(n, nada);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < graf[i].size(); j++){
			int v = graf[i][j];
			desde[v].push_back(i);
		}
	}
	memset(vivo, 1, sizeof vivo);
	dfs(0);
	printf("%d\n", ans.size());
	for(int i = 0; i < ans.size(); i++){
		printf("%d ", ans[i]+1);
	}
	puts("");
}