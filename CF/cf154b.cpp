#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v;
	for(int i = 0; i < n; i++){
		int val; cin >> val;
		v.push_back(val);
	}
	sort(v.begin(), v.end());
	int ans = INT_MAX;
	for(int i = 0; i < v.size(); i++){
		int aux = i + v.size() - (upper_bound(v.begin(), v.end(), 2*v[i]) - v.begin());
		ans = min(ans, aux);
	}
	cout << ans<<'\n';
}
