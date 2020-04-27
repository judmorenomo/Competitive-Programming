#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v;
	for(int i = 0; i < n; i++){
		int val;
		cin >> val;
		v.push_back(val);
	}
	int act = -1*v[0], ans = act;
	for(int i = 0; i < n-1; i++){
		act += v[i]-v[i+1];		
		ans = min(ans, act);
	}
	cout << abs(ans)<<'\n';	
}