#include<bits/stdc++.h>
using namespace std;
vector<int> graf[100010];
double ans[100010];
bool vis[100010];

void dfs(int u){	
	vis[u] = 1;
	double val = 0.0;
	vector<int> hijs;
	for(int i = 0; i < graf[u].size(); i++){
		int v = graf[u][i];
		if(!vis[v]){
			hijs.push_back(v);
			vis[v] = 1;
			dfs(v);
		}
	}	
	for(int i = 0; i < hijs.size(); i++){
		val += ans[hijs[i]];
	}	
	if(hijs.size() != 0){
		val /= 1.0*hijs.size();	
		val+=1.0;
	}
	ans[u] = val;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n-1; i++){
		int ori, fin;
		scanf("%d %d", &ori, &fin);
		ori--; fin--;		
		graf[ori].push_back(fin);
		graf[fin].push_back(ori);
	}

	memset(vis, 0, sizeof vis);
	dfs(0);
	printf("%.8f\n", ans[0]);
}