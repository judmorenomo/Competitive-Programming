#include<bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> m;
vector<pair<double, pair<int, int> > > EdgeList;
vector<pair<int, int> > coord;

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

double dist(int x1, int y1, int x2, int y2){
	int valx = x1-x2, valy = y1-y2;
	return sqrt(valx*valx + valy*valy);
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		m.clear();
		EdgeList.clear();
		coord.clear();
		int s, p, aux = 0;
		scanf("%d %d", &s, &p);
		for(int i = 0; i < p; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			coord.push_back({x,y});
			m[{x,y}] = aux;
			aux++;
		}
		
		for(int i = 0; i < coord.size(); i++){
			for(int j = i+1; j < coord.size(); j++){
				pair<int, int> aux1 = coord[i], aux2 = coord[j];
				int val1 = m[aux1], val2 = m[aux2];
				EdgeList.push_back({dist(aux1.first, aux1.second, aux2.first, aux2.second), {val1, val2}});
			}
		}		
		sort(EdgeList.begin(), EdgeList.end());
		int cc = p;
		double ans = 0;
		UnionFind UF(p);
		for(int i = 0; i < EdgeList.size(); i++){
			pair<double, pair<int, int> > front = EdgeList[i];
			if(!UF.isSameSet(front.second.first, front.second.second)){				
				cc--;
				if(cc == s){					
					ans = front.first;
					break;
				}				
				UF.unionSet(front.second.first, front.second.second);
			}
		}
		printf("%.2f\n", ans);
	}
}