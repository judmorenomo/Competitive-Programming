#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);	
	int ans = 0, pos = 0;
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		int x = (s[i]-'a');
		int val = abs(x-pos);
		int l = pos+26-x, r = 26-pos+x;
		l = min(l, r);
		val = min(val, l);
		pos = x;
		ans += val;
	}
	cout << ans<<'\n';
}
