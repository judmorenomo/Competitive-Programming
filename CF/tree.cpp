#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > graf;
int vals[105], nume[105], suma[105];

int dfs(int u){		
	int cont = (u != 0);	
	for(int i = 0; i < graf[u].size(); i++){
		int v = graf[u][i];							
		cont += dfs(v);		
	}		
	nume[u] = cont;
	return cont;
}
int dfs2(int u){
	int sum = vals[u];
	for(int i = 0; i < graf[u].size(); i++){
		int v = graf[u][i];
		sum += dfs2(v);
	}	
	suma[u] = sum;
	return sum;
}
int main(){
	memset(vals, 0, sizeof vals);
	int n;
	scanf("%d", &n);
	vector<int> aux;
	graf.assign(105, aux);
	for(int i = 0; i < n; i++){
		int pad, val;
		scanf("%d %d", &pad, &val);
		graf[pad].push_back(i+1);
		vals[i+1] = val;		
	}
	dfs(0);
	dfs2(0);
	double res = 0;
	for(int i = 1; i <= n; i++){
		double cant = nume[i], sumAux = suma[i];
		res = max(res, sumAux/cant);
	}
	printf("%.3f\n", res);
}