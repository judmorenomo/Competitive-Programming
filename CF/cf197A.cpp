#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	getline(cin, s);
	vector<int> v;
	for(int i = 0; i < s.size(); i+=2){
		v.push_back(s[i]-'0');
	}
	sort(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++){
		cout << v[i];
		if(i != v.size()-1)cout << '+';
	}
	cout <<'\n';	
}
