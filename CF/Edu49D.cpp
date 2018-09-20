#include<bits/stdc++.h>
using namespace std;
vector<int> graf[200010];
int color[200010], cost[200010], parent[200010], pri, ult;

bool dfs(int u){
	color[u] = 1;	
	for(int i = 0; i < graf[u].size(); i++){
		int v = graf[u][i];		
		if(color[v] == -1){
			parent[v] = u;			
			if(dfs(v)){
				color[u] = 2;
				return true;
			}
		}else if(color[v] == 1){
			color[u] = 2;
			ult = u;
			pri = v;
			return true;
		}
	}
	color[u] = 2;
	return false;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		cost[i] = val;
	}
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		val--;
		graf[i].push_back(val);
	}
	int res = 0;
	memset(color, -1, sizeof color);
	for(int i = 0; i < n; i++){
		if(color[i] == -1){
			int aux = 100050;
			if(dfs(i)){
				vector<int> ciclo;
				ciclo.push_back(pri);
				aux = min(aux, cost[pri]);				
				for(int j = ult; j != pri; j = parent[j]){					
					aux = min(aux, cost[j]);					
				}				
				res += aux;
			}
		}
	}
	printf("%d\n", res);
}