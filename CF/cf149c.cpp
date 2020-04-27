#include<bits/stdc++.h>
using namespace std;
map<pair<int, int>, int> dist;
map<pair<int, int>, bool> allo;

int dx[8] = {-1,-1,-1,0,1,1, 1, 0};
int dy[8] = {-1, 0, 1,1,1,0,-1,-1};

bool valid(int x, int y){
	return allo[{x, y}] && x >= 0 && x <= 1e9 && y >= 0 && y < 1e9;
}

int main(){		
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		int r, a, b;
		cin >> r >> a >> b;
		for(int j = a; j <= b; j++){
			allo[{r, j}]= 1;
		}
	}	
	allo[{x2, y2}] = 1;
	queue<pair<int, int> > q;
	q.push({x1, y1});
	dist[{x1, y1}] = 0;
	while(!q.empty()){
		pair<int, int> f = q.front(); q.pop();	
		if(f.first == x2 && f.second == y2)break;	
		for(int i = 0; i < 8; i++){
			int nx = f.first + dx[i], ny = f.second + dy[i];
			if(valid(nx, ny) && dist.find({nx, ny}) == dist.end()){
				q.push({nx, ny});
				dist[{nx, ny}] = dist[{f.first, f.second}]+1;
			}
		}
	}	
	if(dist.find({x2, y2}) == dist.end())cout << "-1\n";
	else cout << dist[{x2, y2}]<<'\n';
}
