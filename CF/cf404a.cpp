#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	map<string, int> val;
	val["Tetrahedron"] = 4;
	val["Cube"] = 6;
	val["Octahedron"] = 8;
	val["Dodecahedron"] = 12;
	val["Icosahedron"] = 20;
	cin >> n;
	int ans = 0;
	for(int i = 0; i < n; i++){
		string a;
		cin >> a;
		ans += val[a];
	}
	cout << ans<<'\n';
}
