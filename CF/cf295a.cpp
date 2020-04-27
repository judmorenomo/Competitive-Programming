#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	set<char> ss;
	for( auto &c : s){
		ss.insert(tolower(c));
	}
	if(ss.size() == ('z' - 'a' + 1))cout << "YES\n";
	else cout << "NO\n";
}
