#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, sum = 0;
	cin >> n;
	vector<int> c;
	for(int i = 0; i < n; i++){
		int val; cin >> val;
		c.push_back(val);
		sum += val;
	}
	sort(c.begin(), c.end());
	int ans = 0, pos = n-1, act = 0;
	while(act <= (sum - act)){
		act += c[pos];
		pos--;
		ans++;
	}	
	cout << ans<<'\n';
}
