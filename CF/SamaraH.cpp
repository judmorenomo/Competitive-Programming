#include<bits/stdc++.h>
using namespace std;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n, m, d;
	cin >> n >> m >> d;	
	char mat[n][m];
	int dist[n][m];
	bool vis[n][m];
	memset(dist, 0, sizeof dist);
	memset(vis, 0, sizeof vis);
	int sx, sy, fx, fy;
	queue<pair<int, int> > q;
	for(int i = 0; i < n; i++){		
		for(int j = 0; j < m; j++){
			char c; cin >> c;
			if(c == 'S'){
				sx = i, sy = j;
			}
			if(c == 'F'){
				fx = i, fy = j;
			}
			if(c == 'M'){				
				q.push({i, j});
				dist[i][j] = 0;
				vis[i][j] = 1;
			}
			mat[i][j] = c;			
		}
	}
	bool pos = true;
	while(!q.empty()){		
		pair<int, int> u = q.front(); q.pop();
		int x = u.first, y = u.second;		
		if(dist[x][y] > d)break;
		mat[x][y] = 'M';
		if( (x == sx && y == sy) || (x == fx && x == fy)){
			pos = false;
			break;
		}		
		for(int i = 0; i < 4; i++){
			int x2 = x+dr[i], y2 = y+dc[i];
			if(x2 >= 0 && x2 < n && y2 >= 0 && y2 < m){
				if(!vis[x2][y2]){
					dist[x2][y2] = dist[x][y]+1;
					vis[x2][y2] = 1;					
					q.push({x2, y2});
				}
			}
		}
	}
	if(!pos)cout << "-1\n";
	else{		
		memset(vis, 0, sizeof vis);
		memset(dist, 0, sizeof dist);
		vis[sx][sy] = 1;
		dist[sx][sy] = 0;
		queue<pair<int, int > > q2;
		q2.push({sx, sy});
		while(!q2.empty()){			
			pair<int, int> u = q2.front(); q2.pop();
			if(u.first == fx && u.second == fy)break;
			for(int i = 0; i < 4; i++){
				int ro = u.first+dr[i], co = u.second+dc[i];
				if(ro >= 0 && ro < n && co >= 0 && co < m){
					if(!vis[ro][co] && (mat[ro][co] != 'M')){
						q2.push({ro, co});
						vis[ro][co] = 1;
						dist[ro][co] = dist[u.first][u.second]+1;
					}
				}
			}
		}
		if(dist[fx][fy] == 0)cout << "-1\n";
		else cout << dist[fx][fy]<<'\n';
	}
}