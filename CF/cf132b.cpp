#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, r = -1, p1 = -1, p2 = INT_MAX, a, b;
	cin >> n;
	for(int i = 0; i < n; i++){
		int val; cin >> val;
		r = max(r, val);
	}
	int m;
	cin >> m;
	for(int i = 0; i < m; i++){
		int val; cin >> val;
		p1 = max(p1, val);
	}
	int k;
	cin >> k;
	for(int i = 0; i < k; i++){
		int val; cin >> val;
		p2 = min(val, p2);
	}
	cin >> a >> b;
	long long num = 1ll*b*p1*r*r, den = 1ll*p1*b+1ll*p2*a;
	cout <<setprecision(10)<< sqrt(1.0*num/den)<<'\n';
}
