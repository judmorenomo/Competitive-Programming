#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	string ans(" ", n);	
	if(n % 2){
		int act = n/2, nR = act+1, nL = act-1, pos = 0;
		ans[act] = s[pos++];
		for(int i = 0; i < n/2; i++){
			ans[nL--] = s[pos++];
			ans[nR++] = s[pos++];
		}				
	}else {
		int nL = (n/2)-1, nR = n/2, pos = 0;
		for(int i = 0; i < n/2; i++){
			ans[nL--] = s[pos++];
			ans[nR++] = s[pos++];
		}
	}
	cout << ans<<'\n';
}
