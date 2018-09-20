#include<bits/stdc++.h>
using namespace std;
vector<pair<int, pair<int, int> > > EdgeList;
vector<pair<int, int> > mst;
int fmst = 0, smst = 987654321;

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
	int t;
	scanf("%d", &t);
	while(t--){
		EdgeList.clear();
		mst.clear();
		fmst = 0;
		smst = 987654321;
		int n, m;
		scanf("%d %d", &n, &m);
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
				fmst += front.first;
				mst.push_back({front.second.first, front.second.second});
				UF.unionSet(front.second.first, front.second.second);
			}
		}			
		for(int i = 0; i < mst.size(); i++){
			int cc = n;
			UnionFind UF2(n);
			int aux = 0;
			for(int j = 0; j < EdgeList.size(); j++){
				pair<int, pair<int, int> > front = EdgeList[j];								
				if(!UF2.isSameSet(front.second.first, front.second.second) && front.second != mst[i]){
					aux += front.first;
					UF2.unionSet(front.second.first, front.second.second);
					cc--;
				}
			}			
			if(cc == 1)	smst = min(smst, aux);
		}
		printf("%d %d\n", fmst, smst);
	}
}