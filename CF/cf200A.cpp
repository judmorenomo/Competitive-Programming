#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<string> v;
	while(n--){
		string s;
		cin >> s;
		v.push_back(s);
	}
	int ans = 1;
	bool lastC = false;
	string last = v[0];
	for(int i = 1; i < v.size(); i++){
		if(last[1] == v[i][0]){
			ans++;			
		}
		last = v[i];			
	}
	cout << ans<<'\n';
}
