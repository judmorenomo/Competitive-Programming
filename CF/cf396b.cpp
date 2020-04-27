#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v;
	for(int i = 0; i < n; i++){
		int val;
		cin >> val;
		v.push_back(val);
	}
	sort(v.begin(), v.end());
	bool pos = false;
	for(int i = 0; i < n-2; i++){
		int a = v[i], b = v[i+1], c = v[i+2];
		if(a+b > c && a+c > b && b+c > a)pos = true;
	}
	if(!pos)cout << "NO\n";
	else cout << "YES\n";
}
