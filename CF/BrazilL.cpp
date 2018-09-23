#include<bits/stdc++.h>
using namespace std;

vector<int> graf[100010];
int depth[100010], parent[20][100010];
bool vis[100010];

void dfs(int u){
	vis[u] = 1;
	for(int i = 0; i < graf[u].size(); i++){
		int v = graf[u][i];
		if(!vis[v]){
			parent[0][v] = u;
			depth[v] = depth[u] + 1;
			for(int j = 1; j < 20; j++){
				if(parent[j-1][v] != -1){
					parent[j][v] = parent[j-1][parent[j-1][v]];
				}
			}
			dfs(v);
		}
	}
}

int lca(int u, int v){
	int val1 = depth[u], val2 = depth[v];
	if(val2 > val1)swap(u, v);
	int k = depth[u]-depth[v];
	for(int i = 0; i < 20; i++){
		if(k & 1)u = parent[i][u];
		k >>= 1;
	}
	if(u == v)return v;
	for(int i = 19; i >= 0; i--){
		if(parent[i][u] != parent[i][v]){
			u = parent[i][u];
			v = parent[i][v];
		}
	}
	return parent[0][v];
}

int dist(int u, int v){
	int l = lca(u, v);
	return depth[u]+depth[v]-2*depth[l] + 1;
}

int main(){
	int n, q;
	scanf("%d %d" ,&n, &q);
	for(int i = 0; i < n-1; i++){
		int ori, fin;
		scanf("%d %d", &ori, &fin);
		ori--; fin--;
		graf[ori].push_back(fin);
		graf[fin].push_back(ori);		
	}		

	memset(depth, 0, sizeof depth);
	memset(vis, 0, sizeof vis);
	memset(parent, -1, sizeof parent);
	dfs(0);

	for(int i = 0; i < q; i++){
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		a--; b--;
		c--; d--;
		int aux = dist(a, b) + dist(c, d), aux2 = min(dist(a, c) + dist(b, d), dist(a, d) + dist(b, c)), ans;
		if(aux2 > aux)ans = 0;
		else ans = (aux-aux2)/2 + 1;
		printf("%d\n", ans);
	}

}

