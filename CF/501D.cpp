#include<bits/stdc++.h>
using namespace std;
int main(){	
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	long long n, k, s;
	cin >> n >> k >> s;
	if(k > s || (n-1)*k < s){
		cout << "NO\n";
		return 0;
	}
	int pos = 1;
	cout << "YES\n";
	while(k > 0){
		long long nuev = min(n-1, s - k + 1);		
		if(pos - nuev > 0){
			pos = pos - nuev;
		}else pos = pos + nuev;
		k--;
		s -= nuev;
		cout << pos<<" ";
	}
	cout <<'\n';
}