#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, x, y, k;
	cin >> n >> m >> x >> y >> k;
	vector<pair<int, int>> v;
	for(int i = 0; i < k; i++){
		int a, b;
		cin >> a >> b;
		v.push_back({a, b});
	}
	long long ans = 0;
	for(int i = 0; i < k; i++){		
		int vx = INT_MAX, vy = INT_MAX, dx = v[i].first, dy = v[i].second;
		if(!dx && !dy)continue;
		int limX = dx < 0 ? 1 : n, limY = dy < 0 ? 1 : m;
		if(dy)vy = abs(y-limY)/abs(dy);
		if(dx)vx = abs(x-limX)/abs(dx);
		int val = min(vx, vy);
		ans += 1ll*val;
		x += dx*val;
		y += dy*val;
	}
	cout << ans<<'\n';
}
