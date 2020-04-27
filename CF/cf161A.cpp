#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ans = 0;
	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			int val;
			cin >> val;
			if(val == 1){
				ans = abs(i-2)+abs(j-2);
			}
		}
	}
	cout << ans<<'\n';
}
