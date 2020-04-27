#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	bool yes = true;
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c; cin >> c;
			if(c != 'B' && c != 'G' && c != 'W')yes = false;
		}
	}
	cout << (yes ? "#Black&White\n" : "#Color\n");
}
