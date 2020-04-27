#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	long long ans = k;
	int cont = 0;
	while(n--){
		char opt;
		int val;
		cin >> opt >> val;
		if(opt == '+'){
			ans += 1ll*val;
		}else {
			if(1ll*val > ans){
				cont++;
			}else {
				ans -= 1ll*val;
			}
		}
	}
	cout << ans<<" "<<cont<<'\n';
}
