#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > graf;
bool vis[1010];
int distT[1010], distS[1010];
bool adj[1010][1010];

int main(){
	int n, m, s, t;
	scanf("%d %d %d %d", &n, &m, &s, &t);
	graf.assign(n, vector<int>());
	s--;
	t--;
	for(int i = 0; i < m; i++){
		int ori, fin;
		scanf("%d %d", &ori, &fin);
		ori--;
		fin--;
		graf[ori].push_back(fin);
		graf[fin].push_back(ori);
		adj[ori][fin] = adj[fin][ori] = 1;
	}	
	memset(vis, 0, sizeof vis);
	memset(distT, 0, sizeof distT);
	memset(distS, 0, sizeof distS);
	queue<int> q;
	q.push(t);
	vis[t] = 1;
	distT[t] = 0;	

	while(!q.empty()){
		int u = q.front();q.pop();
		for(int i = 0; i < graf[u].size(); i++){
			int v = graf[u][i];
			if(!vis[v]){
				q.push(v);
				distT[v] = distT[u]+1;
				vis[v] = 1;
			}
		}
	}
	memset(vis, 0, sizeof vis);
	q.push(s);
	vis[s] = 1;
	distS[s] = 0;	

	while(!q.empty()){
		int u = q.front();q.pop();
		for(int i = 0; i < graf[u].size(); i++){
			int v = graf[u][i];
			if(!vis[v]){
				q.push(v);
				distS[v] = distS[u]+1;
				vis[v] = 1;
			}
		}
	}
	int distMin = distT[s];
	int ans = 0;
	for(int i = 0; i < n; i++){						
		for(int j = 0; j < n; j++){
			if(adj[i][j] || i == j)continue;						
			if(min(distS[i]+distT[j], distS[j]+distT[i])+1 >= distMin)ans++;
		}
	}
	printf("%d\n", ans/2);
	return 0;
}