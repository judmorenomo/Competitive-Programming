#include<bits/stdc++.h>
using namespace std;
int main(){
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	int n;
	vector<int> v;
	cin >> n;
	for(int i = 0; i < n; i++){
		int val;
		cin >> val;
		if(val)v.push_back(i);
	}	
	long long ans = 1;
	if(v.size() < 2)cout << v.size()<<'\n';
	else {
		for(int i = 0; i < v.size()-1; i++){
			ans *= 1ll*(v[i+1]-v[i]);
		}
		cout << ans<<'\n';
	}
}
