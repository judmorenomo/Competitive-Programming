#include<bits/stdc++.h>
using namespace std;
long long ant = 0, nuev = 0;
vector<pair<int, pair<int, int> > > EdgeList;
bool flag = false;

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
int main(){
	//freopen("in.txt", "r", stdin);
	int n;

	while(scanf("%d", &n) != EOF){
		EdgeList.clear();
		ant = 0;
		nuev = 0;
		for(int i = 0; i < n-1; i++){
			int ori, fin, w;
			scanf("%d %d %d", &ori, &fin, &w);
			ant += w;
		}		
		int k;
		scanf("%d", &k);
		for(int i = 0; i < k; i++){
			int ori, fin, w;
			scanf("%d %d %d", &ori, &fin, &w);
			ori--;
			fin--;
			EdgeList.push_back({w, {ori, fin}});
		}
		int m;
		scanf("%d", &m);
		for(int i = 0; i < m; i++){
			int ori, fin, w;
			scanf("%d %d %d", &ori, &fin, &w);
			ori--;
			fin--;
			EdgeList.push_back({w, {ori, fin}});
		}
		sort(EdgeList.begin(), EdgeList.end());
		UnionFind UF(n);
		for(int i = 0; i < EdgeList.size(); i++){
			pair<int, pair<int, int > > front = EdgeList[i];			
			if(!UF.isSameSet(front.second.first, front.second.second)){				
				nuev += front.first;
				UF.unionSet(front.second.first, front.second.second);
			}			
		}
		if(!flag)flag = true;
		else puts("");
		printf("%lld\n%lld\n", ant, nuev);
	}
}