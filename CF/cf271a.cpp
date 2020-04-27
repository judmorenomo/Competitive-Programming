#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string a = "qwertyuiop", b = "asdfghjkl;", c = "zxcvbnm,./";
	map<char, char> l, r;
	for(int i = 0; i < a.size(); i++){
		if(i > 0)l[a[i]] = a[i-1];
		if(i != a.size()-1)r[a[i]] = a[i+1];
	}
	for(int i = 0; i < b.size(); i++){
		if(i > 0)l[b[i]] = b[i-1];
		if(i != b.size()-1)r[b[i]] = b[i+1];
	}
	for(int i = 0; i < c.size(); i++){
		if(i > 0)l[c[i]] = c[i-1];
		if(i != c.size()-1)r[c[i]] = c[i+1];
	}
	string val, q;
	cin >> val >> q;
	if(val == "R"){
		for(int i = 0; i < q.size(); i++){
			cout << l[q[i]];
		}
		cout <<'\n';
	}else {
		for(int i = 0; i < q.size(); i++){
			cout << r[q[i]];
		}
		cout <<'\n';
	}
}
