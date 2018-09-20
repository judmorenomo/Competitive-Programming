#include<bits/stdc++.h>
using namespace std;
int mat[2005][2005];
int dist[2005][2005];
int dr[5] = {1,0,-1,0};
int	dc[5] = {0,1,0,-1};
set<pair<int, int> > dest;
pair<int, int> last;

bool valid(int r, int c){
	return r >= 0 && r <= 2000 && c >= 0 && c <= 2000;
}
int main(){
	int p;
	scanf("%d", &p);
	while(p){
		dest.clear();
		memset(dist, 0, sizeof dist);
		memset(mat, 0, sizeof mat);
		queue<pair<int, int > > q;
		for(int i = 0; i < p; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			mat[x][y] = 1;
			q.push({x, y});			
			dist[x][y] = 0;
		}		
		int p2;
		scanf("%d", &p2);
		for(int i = 0; i < p2; i++){
			int x, y;
			scanf("%d %d", &x, &y);
			dest.insert({x, y});		
		}
		
		while(!q.empty()){
			pair<int, int> u = q.front(); q.pop();						
			last = u;		
			if(dest.find({u.first, u.second}) != dest.end())break;
			for(int i = 0; i < 4; i++){
				int dx = u.first+dr[i], dy = u.second+dc[i];
				if(valid(dx, dy)){
					if(mat[dx][dy]!= 1){
						mat[dx][dy] = 1;
						dist[dx][dy] = dist[u.first][u.second] + 1;
						q.push({dx, dy});
					}
				}
			}
		}
		printf("%d\n", dist[last.first][last.second]);
		scanf("%d", &p);
	}
}