#include<bits/stdc++.h>
using namespace std;

int deb[110];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b, val;
		cin >> a >> b >> val;
		a--; b--;
		deb[a] -= val; deb[b] += val;
	}
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(deb[i] > 0) ans += deb[i];
	}
	cout << ans<<'\n';
}
