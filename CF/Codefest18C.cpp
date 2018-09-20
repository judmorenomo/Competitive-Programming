#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n;
	cin >> n;
	cin.ignore();
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int ans = 0;
	for(int i = 0; i < n; i++){
		if(i != n-1){
			if(s1[i] == s2[i+1] && s2[i] == s1[i+1] && s1[i] != s2[i] && s1[i+1] != s2[i+1]){
				ans++;
				i++;
				continue;
			}
		}
		if(s1[i] != s2[i]){
			ans++;
			continue;
		}
	}
	cout << ans<<'\n';
}