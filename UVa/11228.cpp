#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int> > points;
int states = 1, may;
double longR = 0.0, shortR = 0.0;

class UnionFind {
	private: vector<int> p, rank;
	public:
		UnionFind(int N) { rank.assign(N, 0);
			p.assign(N, 0); for(int i = 0; i < N; i++) p[i] = i; }
		int findSet(int i ){return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
		bool isSameSet(int i, int j){return findSet(i) == findSet(j); }
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

double dist(int x1, int y1, int x2, int y2){
	double val1 = x1-x2, val2 = y1-y2;
	return sqrt(val1*val1 + val2*val2);
}

int rond(double val){
	return (int)(val+0.5);
}

int main(){
	int t, test = 1;
	scanf("%d", &t);
	while(t--){
		states = 1;
		longR = 0.0;
		shortR = 0.0;		
		points.clear();
		int n;
		scanf("%d %d", &n, &may);
		for(int i = 0; i < n; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			points.push_back({x, y});
		}
		vector<pair<double, pair<int, int> > > EdgeList;
		for(int i = 0; i < n; i++){
			for(int j = i+1; j < n; j++){
				int x1 = points[i].first, y1 = points[i].second, x2 = points[j].first, y2 = points[j].second;		
				double d = dist(x1, y1, x2, y2);		
				EdgeList.push_back({d, {i, j}});
			}
		}		
		
		sort(EdgeList.begin(),EdgeList.end());
		UnionFind UF(n);
		for(int i = 0; i < EdgeList.size(); i++){
			pair<double, pair<int, int> > front = EdgeList[i];
			if(!UF.isSameSet(front.second.first, front.second.second)){
				double valor = front.first;
				if(valor <= may)shortR += valor;
				else{
					states++;
					longR += valor;
				}				
				UF.unionSet(front.second.first, front.second.second);
			}
		}		
		printf("Case #%d: %d %d %d\n", test, states, rond(shortR), rond(longR));
		test++;
	}	
}