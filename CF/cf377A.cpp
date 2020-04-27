#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int k, r;
	cin >> k >> r;
	int ans = 1;
	while(true){
		int val = k*ans;		
		if(val%10 == r || val % 10 == 0)break;
		ans++;
	}
	cout << ans<<'\n';
}
