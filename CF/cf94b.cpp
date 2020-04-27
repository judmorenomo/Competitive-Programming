#include<bits/stdc++.h>
using namespace std;

int deg[110];
vector<int> graf[110];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--; b--;
		graf[a].push_back(b);
		graf[b].push_back(a);
		deg[a]++;
		deg[b]++;
	}
	queue<int> cur;
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(deg[i] == 1){
			cur.push(i);			
		}
	}
	int na = 0;
	while(!cur.empty()){
		ans++;		
		while(!cur.empty()){
			int val = cur.front(); cur.pop();
			deg[val] = 0;
			for(int i = 0; i < graf[val].size(); i++){
				int v = graf[val][i];
				deg[v]--;				
			}
		}
		for(int i = 0; i < n; i++){
			if(deg[i] == 1)cur.push(i);
		}		
	}
	cout << ans<<'\n';
}
