#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long l, r;
	cin >> l >> r;
	if(r == l+1)cout << "-1\n";
	else if(l % 2 == 0 && r >= l+2)cout << l<<" "<<l+1<<" "<<l+2<<'\n';
	else if(r >= l + 3)cout << l+1<<" "<<l+2<<" "<<l+3<<'\n';
	else {
		cout << "-1\n";
	}
}