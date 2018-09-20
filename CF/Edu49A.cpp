#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		bool ans = true;
		int n; cin >> n;
		string s;
		cin >> s;
		int l = 0, r = s.size()-1;
		while(l < r){
			int valL = s[l]-'a', valR = s[r]-'a';
			if(!(abs(valL-valR) == 0 || abs(valL-valR) == 2))ans = false;
			l++; r--;
		}
		if(ans)cout << "YES\n";
		else cout << "NO\n";
	}
}