#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	set<int> s;
	for(int i = 0; i < 4; i++){
		int val;
		cin >> val;
		s.insert(val);
	}
	cout << 4 - s.size()<<'\n';
}
