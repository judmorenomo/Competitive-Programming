#include<bits/stdc++.h>
using namespace std;
vector<pair<long long, pair<int, int> > > EdgeList;
vector<long long>ans;

class UnionFind{
private: vector<int> p, rank;
public:
	UnionFind(int N){
		p.assign(N, 0);
		rank.assign(N, 0);
		for(int i = 0; i < N; i++)p[i] = i;
	}	
	int findSet(int i){
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}
	bool isSameSet(int i, int j){
		return findSet(i) == findSet(j);
	}
	void unionSet(int i , int j){
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

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	while(n || m){
		ans.clear();
		EdgeList.clear();
		for(int i = 0; i < m; i++){
			int ori, fin;
			long long w;
			scanf("%d %d %lld", &ori, &fin, &w);
			EdgeList.push_back({w, {ori, fin}});
		}
		sort(EdgeList.begin(), EdgeList.end());		
		UnionFind UF(n);
		for(int i = 0; i < EdgeList.size(); i++){
			pair<long long, pair<int, int > > front = EdgeList[i];
			if(!UF.isSameSet(front.second.first, front.second.second))UF.unionSet(front.second.first, front.second.second);
			else ans.push_back(front.first);
		}
		if(ans.size() == 0)puts("forest");
		else{
			sort(ans.begin(), ans.end());
			printf("%lld", ans[0]);
			for(int i = 1; i < ans.size(); i++){
				printf(" %lld", ans[i]);
			}
			puts("");
		}

		scanf("%d %d", &n, &m);
	}
}