#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s, s2;
	cin >> s;	
	s2 = s;
	reverse(s2.begin(), s2.end());
	cout << s<<s2<<'\n';
}
