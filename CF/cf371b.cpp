#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, men = INT_MAX, may = -1, dist = 0;
	cin >> n;
	map<int, int> cont;
	for(int i = 0; i < n; i++){
		int val; cin >> val;
		men = min(men, val);
		may = max(may, val);
		if(cont.find(val) == cont.end())dist++;
		cont[val]++;
	}
	int val = may - men;
	if(val % 2 && dist != 2){		
		cout << "NO\n";
	}else {		
		if(dist == 2 || cont[may]+cont[men]+cont[men + val/2] == n || cont[may] == n)cout << "YES\n";
		else cout << "NO\n";
	}
}
