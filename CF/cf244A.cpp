#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, ans = 0, pol = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		int val;
		cin >> val;
		if(val == -1){
			if(pol == 0)ans++;
			else pol--;
		}else {
			pol+=val;
		}
	}
	cout << ans<<'\n';
}
