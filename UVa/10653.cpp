#include<bits/stdc++.h>
using namespace std;
char mat[1005][1005];
int dist[1005][1005];
bool vis[1005][1005];
int dr[4] = {1,0,-1,0};
int dc[4] = {0,1,0,-1};
int r, c;

bool valid(int x, int y){
	return x >= 0 && x < r && y >= 0 && y < c && mat[x][y] != '#';
}
int main(){	
	scanf("%d %d", &r, &c);
	while(r || c){
		memset(mat, '.', sizeof mat);
		memset(dist, 0, sizeof dist);
		int b;
		scanf("%d", &b);
		for(int i = 0; i < b; i++){
			int id, num;
			scanf("%d %d", &id, &num);
			while(num--){
				int col;
				scanf("%d", &col);
				mat[id][col] = '#';
			}			
		}
		int sx, sy, fx, fy;
		scanf("%d %d", &sx, &sy);
		scanf("%d %d", &fx, &fy);
		memset(vis, 0, sizeof vis);
		queue<pair<int, int> > q;
		vis[sx][sy] = 1;
		dist[sx][sy] = 0;
		q.push({sx, sy});
		while(!q.empty()){
			pair<int, int> u = q.front(); q.pop();
			if(u.first == fx && u.second == fy)break;
			for(int i = 0; i < 4; i++){
				int dx = u.first+dr[i], dy = u.second+dc[i];
				if(valid(dx, dy)){
					if(!vis[dx][dy]){
						vis[dx][dy] = 1;
						dist[dx][dy] = dist[u.first][u.second] + 1;
						q.push({dx, dy});
					}
				}
			}
		}
		printf("%d\n", dist[fx][fy]);
		scanf("%d %d", &r, &c);
	}
}