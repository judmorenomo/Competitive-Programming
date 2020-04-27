#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a;
	getline(cin, a);
	set<char> ss;
	for(int i = 1; i < a.size()-1; i++){
		if(a[i] >= 'a' && a[i] <= 'z'){
			ss.insert(a[i]);
		}
	}
	cout << ss.size()<<'\n';
}
