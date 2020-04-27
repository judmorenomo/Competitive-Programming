#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, b, d;
	cin >> n >> b >> d;
	int ans = 0, aux = 0;
	for(int i = 0; i < n; i++){
		int val;
		cin >> val;
		if(val > b)continue;
		aux += val;
		if(aux > d){
			ans++;
			aux = 0;
		}
	}
	cout << ans<<'\n';
}
