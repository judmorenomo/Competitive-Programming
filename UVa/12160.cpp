#include<bits/stdc++.h>
using namespace std;
bool vis[10000];
vector<vector<int> > graf;
vector<int> vals;
int dist[10000];

int main(){
	//freopen("in.txt", "r", stdin);
	int l, u, r, cas = 1;
	scanf("%d %d %d", &l, &u, &r);
	while(l || u || r){
		graf.clear();
		vals.clear();
		while(r--){
			int val;
			scanf("%d", &val);
			vals.push_back(val);
		}
		graf.assign(10000, vector<int>());
		memset(vis, 0, sizeof vis);
		queue<int> q;
		vis[l] = 1;
		q.push(l);
		while(!q.empty()){
			int f = q.front(); q.pop();
			for(int i = 0; i < vals.size(); i++){
				int s = (f + vals[i])%10000;
				if(!vis[s]){
					vis[s] = 1;
					q.push(s);
					graf[f].push_back(s);
					graf[s].push_back(f);
				}
			}
		}	
		printf("Case %d: ", cas);
		cas++;
		if(!vis[u])puts("Permanently Locked");
		else{
			memset(dist, 0, sizeof dist);
			memset(vis, 0, sizeof vis);
			queue<int> q2;
			q2.push(l);
			vis[l] = 1;
			dist[l] = 0;
			while(!q2.empty()){
				int f = q2.front(); q2.pop();
				if(f == u)break;
				for(int i = 0; i < graf[f].size(); i++){
					int v = graf[f][i];
					if(!vis[v]){					
						vis[v] = 1;
						dist[v] = dist[f]+1;
						q2.push(v);
					}
				}
			}
			printf("%d\n", dist[u]);
		}
		scanf("%d %d %d", &l, &u, &r);
	}
}