#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ans = 0, pos = 0;
	while(pos < n){
		char act = s[pos];
		int tot = 1;
		pos++;
		while(s[pos] == act && pos < n){
			tot++;
			pos++;
		}
		ans += tot-1;
	}
	cout << ans<<'\n';
}
