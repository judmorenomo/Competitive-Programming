#include<bits/stdc++.h>
using namespace std;

vector<pair<int, pair<int, int> > > EdgeList;
long long tot = 0, mst = 0;

class UnionFind{
private: vector<int> p, rank;
public:
	UnionFind(int N){
		p.assign(N, 0);
		rank.assign(N, 0);
		for(int i = 0; i <N; i++)p[i] = i;
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
				if(rank[x] == rank[y]) rank[y]++;
			}
		}
	}
};

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	while(n || m){
		EdgeList.clear();
		tot = 0;
		mst = 0;
		for(int i = 0; i < m; i++){
			int ori, fin, w;
			scanf("%d %d %d", &ori, &fin, &w);
			tot += w;
			EdgeList.push_back({w, {ori, fin}});			
		}
		sort(EdgeList.begin(), EdgeList.end());
		UnionFind UF(n);
		for(int i = 0; i < EdgeList.size(); i++){
			pair<int, pair<int, int> > front = EdgeList[i];
			if(!UF.isSameSet(front.second.first, front.second.second)){
				mst += front.first;
				UF.unionSet(front.second.first, front.second.second);
			}
		}
		printf("%lld\n", tot-mst);
		scanf("%d %d", &n, &m);
	}
}