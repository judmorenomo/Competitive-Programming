#include<bits/stdc++.h>
using namespace std;
int parent[20][100010], depth[100010];
vector<vector<pair <int, pair<int, int > > > >  graf;
int to_root[100010], from_root[100010];

void dfs(int u, int pad = 0, long long cost1 = 0, long long cost2 = 0){
	from_root[u] = cost1;	
	to_root[u] = cost2;
	parent[0][u] = pad;
	for(int i = 0; i < graf[u].size(); i++){
		if(graf[u][i].first == pad)continue;
		depth[graf[u][i].first] = depth[u]+1;
		dfs(graf[u][i].first, u, cost1 + graf[u][i].second.first, cost2 + graf[u][i].second.second);
	}
}

int lca(int u, int v){
	int val1 = depth[u], val2 = depth[v];
	if(val2 > val1) swap(u, v);
	int k = depth[u]-depth[v];
	for(int i = 0; i < 20; i++){
		if(k & 1) u = parent[i][u];
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

int main(){
	//freopen("in.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while(t--){
		graf.clear();
		memset(parent, -1, sizeof parent);
		memset(depth, 0, sizeof depth);
		memset(to_root, 0, sizeof to_root);
		memset(from_root, 0, sizeof from_root);
		int n;
		long long total = 0;
		scanf("%d", &n);
		vector<pair<int, pair<int, int > > > aux;
		graf.assign(n, aux);
		for(int i = 0; i < n-1; i++){
			int u, v, c1, c2;
			scanf("%d %d %d %d", &u, &v, &c1, &c2);
			u--;
			v--;
			total += c1 + c2;
			graf[u].push_back({v, {c1, c2}});
			graf[v].push_back({u, {c2, c1}});			
		}
		dfs(0);
		for(int i = 1; i < 20; i++){
			for(int j = 0; j < n; j++){
				if(parent[i-1][j] != -1){
					parent[i][j] = parent[i-1][parent[i-1][j]];
				}
			}
		}			

		int q;
		scanf("%d", &q);
		while(q--){			
			int u, v;
			scanf("%d %d", &u, &v);
			u--,
			v--;
			int anc = lca(u, v);
			long long camino = from_root[u] - from_root[anc] + to_root[v] - to_root[anc]; 
			printf("%I64d\n", total - camino);
		}
	}
}