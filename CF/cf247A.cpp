#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	vector<int> v;
	for(int i = 0; i < 4; i++){
		int val;
		cin >> val;
		v.push_back(val);
	}
	int ans = 0;
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		ans += (v[s[i]-'0'-1]);
	}
	cout << ans<<'\n';
}
