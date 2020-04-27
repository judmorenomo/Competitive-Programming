#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	a = max(a, b);
	a = 6 - a + 1;
	int gc = __gcd(a, 6);
	cout << a/gc<<"/"<<6/gc<<'\n';
}
