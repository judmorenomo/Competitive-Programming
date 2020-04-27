#include<bits/stdc++.h>
using namespace std;
vector<int> graf[110];
bool vis[110][110], vis2[110];
int contV, contE;

void dfs(int u){
	if(!vis2[u])contV++; 
	vis2[u] = 1;	
	for(int i = 0; i < graf[u].size(); i++){
		int v = graf[u][i];
		if(!vis[u][v]){
			vis[u][v] = vis[v][u] = 1;
			contE++;
			dfs(v);
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b; a--; b--;
		graf[a].push_back(b);
		graf[b].push_back(a);
	}
	memset(vis2, 0, sizeof vis2);
	int ans = 0, left = 0;
	for(int i = 0; i < n; i++){
		if(!vis2[i]){
			contV = contE = 0;;			
			dfs(i);
			if(contV % 2){
				if(contE == contV)ans++;
				else left++;
			}
		}
	}
	cout << ans + (left%2)<<'\n';
}
