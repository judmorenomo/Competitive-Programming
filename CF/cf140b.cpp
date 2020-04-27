#include<bits/stdc++.h>
using namespace std;

int pos[100010];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;	
	cin >> n;
	for(int i = 0; i < n; i++){
		int val;
		cin >> val;
		pos[val] = i;
	}
	long long l = 0, r = 0;
	int m;
	cin >> m;
	for(int i = 0; i < m; i++){
		int val;
		cin >> val;
		l += 1ll*pos[val] + 1ll;
		r += 1ll*(n - pos[val]);
	}
	cout << l<<" "<<r<<'\n';
}
