#include<bits/stdc++.h>
using namespace std;

char mat[1005][1005];
bool vis[1005][1005];
int n, m;
int dr[5] = {1,0,-1,0};
int dc[5] = {0,1,0,-1};
pair<int, int> last;
int dist[1005][1005];

bool sale(int r, int c){
	return r == 0 || r == n-1 || c == 0 || c == m-1;
}
bool valid(int r, int c){
	return r >= 0 && r < n && c >= 0 && c < m && mat[r][c] == '.';
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){				
		memset(mat, '#', sizeof mat);
		memset(vis, 0, sizeof vis);
		memset(dist, 0, sizeof dist);
		queue<pair<int, int> > q;
		int x0, y0;
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				char c; cin >> c;	
				mat[i][j] = c;	
				if(c == 'J'){
					x0 = i, y0 = j;
					vis[i][j] = 1;
				}else if(c == 'F'){
					q.push({i, j});
					vis[i][j] = 1;	
				}
			}
		}
		q.push({x0, y0});		
		while(!q.empty()){
			pair<int, int> u = q.front(); q.pop();			
			if(mat[u.first][u.second] == 'J'){				
				last = u;
				if(sale(u.first, u.second))break;
				for(int i = 0; i < 4; i++){
					int dx = u.first+dr[i], dy = u.second+dc[i];
					if(valid(dx, dy)){
						if(!vis[dx][dy]){
							mat[dx][dy] = 'J';
							vis[dx][dy] = 1;
							dist[dx][dy] = dist[u.first][u.second]+1;
							q.push({dx, dy});
						}
					}
				}
			}else{				
				for(int i = 0; i < 4; i++){
					int dx = u.first+dr[i], dy = u.second+dc[i];
					if(valid(dx, dy)){
						if(!vis[dx][dy]){
							mat[dx][dy] = 'F';
							vis[dx][dy] = 1;
							q.push({dx, dy});
						}
					}
				}
			}
		}
		if(sale(last.first, last.second)){
			printf("%d\n", dist[last.first][last.second]+1);
		}else puts("IMPOSSIBLE");
	}
}