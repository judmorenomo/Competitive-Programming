#include<bits/stdc++.h>
using namespace std;

long long sum1[100010], sum2[100010];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<long long> v1, v2;
	for(int i = 0; i < n; i++){
		long long val; cin >> val;
		v1.push_back(val);
		v2.push_back(val);
	}
	sort(v2.begin(), v2.end());
	sum1[0] = v1[0];
	sum2[0] = v2[0];
	for(int i = 1; i < n; i++){
		sum1[i] = v1[i]+sum1[i-1];
		sum2[i] = v2[i]+sum2[i-1];
	}	
	int q;
	cin >> q;
	for(int i = 0; i < q; i++){
		int t, l, r;
		cin >> t >> l >> r;
		l--;
		r--;
		if(t == 1) {
			long long ans = sum1[r];
			if(l > 0)ans -= sum1[l-1];
			cout << ans<<'\n';
		}else {
			long long ans = sum2[r];
			if(l > 0)ans -= sum2[l-1];
			cout << ans<<'\n';
		}
	}
}
