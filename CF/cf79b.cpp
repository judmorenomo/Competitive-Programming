#include<bits/stdc++.h>
using namespace std;

string solve(string s){
	int sum = 0;
	for(int i = 0; i < s.size(); i++){
		sum += s[i]-'0';
	}
	return to_string(sum);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	getline(cin, s);
	int ans = 0;
	while(s.size() > 1){
		s = solve(s);
		ans++;
	}
	cout << ans<<'\n';
}
