#include<bits/stdc++.h>
using namespace std;

int cand[1010], dwa[1010];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c; cin >> c;
			if(c == 'G')dwa[i] = j;
			if(c == 'S')cand[i] = j;
		}
	}
	set<int> s;
	for(int i = 0; i < n; i++){
		int val = cand[i]-dwa[i];
		if(val < 0){
			cout << "-1\n";
			return 0;
		}
		s.insert(val);
	}
	cout << s.size()<<'\n';
}
