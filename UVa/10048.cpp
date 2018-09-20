#include<bits/stdc++.h>
using namespace std;
vector<pair<int, pair<int, int> > > EdgeList;
int graf[110][110], ans = -1, ini, dest;
bool pos = false, vis[110];
vector<int> path;

class UnionFind{
private: vector<int> p, rank;
public:
	UnionFind(int N){
		rank.assign(N, 0);
		p.assign(N, 0);
		for(int i = 0; i < N; i++)p[i] = i;			
	}	
	int findSet(int i){
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}
	bool isSameSet(int i, int j){
		return findSet(i) == findSet(j);		
	}
	void unionSet(int i, int j){
		if(!isSameSet(i, j)){
			int x = findSet(i), y = findSet(j);
			if(rank[x] > rank[y])p[y] = x;
			else{
				p[x] = y;
				if(rank[x] == rank[y])rank[y]++;
			}
		}
	}
};

void dfs(int u){
	if(u == dest){
		pos = true;
		for(int i = 0; i < path.size()-1; i++){
			ans = max(ans, graf[path[i]][path[i+1]]);
		}		
		return;
	}
	vis[u] = 1;
	for(int i = 0; i < 105; i++){
		if(graf[u][i] != -1 && !vis[i]){
			path.push_back(i);
			dfs(i);
			path.pop_back();
		}
	}
}

int main(){
	bool flag = false;
	int c, s, q, cont = 1;
	scanf("%d %d %d", &c, &s, &q);
	while(c || s || q){
		EdgeList.clear();
		memset(graf, 0, sizeof graf);
		for(int i = 0; i < s; i++){
			int ori, fin, w;
			scanf("%d %d %d", &ori, &fin, &w);
			ori--;
			fin--;
			EdgeList.push_back({w, {ori, fin}});
		}
		sort(EdgeList.begin(), EdgeList.end());
		UnionFind UF(c);
		memset(graf, -1, sizeof graf);
		for(int i = 0; i < EdgeList.size(); i++){
			pair<int, pair<int, int > > front = EdgeList[i];
			if(!UF.isSameSet(front.second.first, front.second.second)){				
				graf[front.second.first][front.second.second] = graf[front.second.second][front.second.first] = front.first;
				UF.unionSet(front.second.first, front.second.second);
			}
		}
		if(!flag)flag = true;
		else puts("");
		printf("Case #%d\n", cont);
		cont++;
		for(int i = 0; i < q; i++){	
			path.clear();
			memset(vis, 0, sizeof vis);
			ans = -1;
			pos = false;			
			scanf("%d %d", &ini, &dest);
			ini--;
			dest--;	
			path.push_back(ini);
			dfs(ini);
			if(!pos)puts("no path");
			else printf("%d\n", ans);				
		}
		scanf("%d %d %d", &c, &s, &q);
	}
}