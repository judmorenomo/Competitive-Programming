#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;	
	int ans = 0;
	for(int i = 0; i < s.size(); i++){
		bool hasBear = false;
		for(int j = i+3; j < s.size(); j++){			
			string nn = s.substr(j-3, 4);
			if(nn == "bear")hasBear = true;
			if(hasBear)ans++;
		}
	}
	cout << ans<<'\n';
}
