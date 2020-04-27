#include<bits/stdc++.h>
using namespace std;

char mat[110][110];
int vis[300], dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	char c;
	cin >> n >> m >> c;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> mat[i][j];
		}
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(mat[i][j] == c){
				for(int k = 0; k < 4; k++){
					int nx = i + dx[k], ny = j + dy[k];
					if(nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] != c && mat[nx][ny] != '.'){						
						if(!vis[mat[nx][ny]]){
							ans++;
							vis[mat[nx][ny]] = 1;
						}
					}
				}
			}
		}
	}
	cout << ans<<'\n';
}
