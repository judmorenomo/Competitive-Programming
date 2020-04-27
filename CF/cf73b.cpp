#include<bits/stdc++.h>
using namespace std;
char mat[35][35];

int in[35];
int dist[35];

int main(){	
	memset(dist, -1, sizeof dist);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, x;
	cin >> n >> m >> x;
	vector<pair<int, int> > q;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> mat[i][j];
			if(mat[i][j] == 'S'){
				q.push_back({i, j});
			}else {
				in[mat[i][j]-'a'] = 1;				
			}
		}
	}

	for(int i = 0; i < q.size(); i++){
		int x = q[i].first, y = q[i].second;
		for(int j = 0; j < n; j++){
			for(int k = 0; k < m; k++){				
				if(j == x && k == y)continue;
				int val = mat[j][k]-'a';				
				if(dist[val] == -1)dist[val] = (x-j)*(x-j)+(k-y)*(k-y);
				else dist[val] = min(dist[val], (x-j)*(x-j)+(k-y)*(k-y));
			}
		}
	}

	int len, ans = 0;
	bool pos = true;
	cin >> len;
	string que;
	cin >> que;
	for(int i = 0; i < len; i++){		
		int val = tolower(que[i])-'a';
		if(!in[val]){
			pos = false;
			break;
		}		
		else if(que[i] >= 'A' && que[i] <= 'Z'){
			if(q.size() == 0){
				pos = false;
				break;
			}
			int aux = que[i]-'A';
			if(dist[aux] > x*x)ans++;	
		}
	}
	if(!pos)ans = -1;
	cout << ans<<'\n';
}
