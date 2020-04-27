#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, ans = 0;
	cin >> a;
	while(a--){
		int x, y, z;
		cin >> x >> y >> z;
		if(x+y+z >= 2)ans++;
	}
	cout << ans<<'\n';
}
