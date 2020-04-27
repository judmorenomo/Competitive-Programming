#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	vector<pair<int, int> > vec;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		vec.push_back({b, a});
	}
	sort(vec.rbegin(), vec.rend());
	long long ans = 0;
	int cont = n, pos = 0;
	while(cont && pos < m){
		int num = min(cont, vec[pos].second);
		ans += 1ll*num*vec[pos].first;
		cont -= num;
		pos++;
	}
	cout << ans<<'\n';
}
