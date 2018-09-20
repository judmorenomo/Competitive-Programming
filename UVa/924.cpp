#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > graf;
int dist[2505], cont[2505];
bool vis[2505];

int main(){
	int v;
	scanf("%d", &v);
	graf.assign(v, vector<int>());
	for(int i = 0; i < v; i++){
		int n;
		scanf("%d", &n);
		while(n--){
			int val;
			scanf("%d", &val);
			graf[i].push_back(val);			
		}
	}
	int t;
	scanf("%d", &t);
	while(t--){
		int boom = 0, day = 0;
		memset(dist, 0, sizeof dist);
		memset(cont, 0, sizeof cont);
		memset(vis, 0, sizeof vis);
		queue<int> q;
		int source;
		scanf("%d", &source);
		dist[source] = 0;
		vis[source] = 1;
		q.push(source);
		while(!q.empty()){
			int u = q.front(); q.pop();			
			for(int i = 0; i < graf[u].size(); i++){
				int v = graf[u][i];
				if(!vis[v]){
					vis[v] = 1;
					dist[v] = dist[u]+1;
					cont[dist[v]]++;
					q.push(v);
					if(cont[dist[v]] > boom){
						day = dist[v];
						boom = cont[dist[v]];
					}
				}
			}
		}
				
		if(!boom)puts("0");
		else{
			printf("%d %d\n", boom, day);
		}
	}
}