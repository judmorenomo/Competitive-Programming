#include<bits/stdc++.h>
using namespace std;

bool vis[20010];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	queue<pair<int, int> > q;
	vis[n] = 1;
	q.push({n, 0});
	while(!q.empty()){
		pair<int, int> f = q.front(); q.pop();
		if(f.first == m){
			cout << f.second<<'\n';
			return 0;
		}
		int opt1 = 2*f.first, opt2 = f.first-1;
		if(opt1 <= 2*m && !vis[opt1]){
			vis[opt1] = 1;
			q.push({opt1, f.second+1});
		}
		if(opt2 > 0 && !vis[opt2]){
			vis[opt2] = 1;
			q.push({opt2, f.second+1});
		}
	}
}
