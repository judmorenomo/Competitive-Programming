#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	map<char, int> cont;
	int ans = 0;
	string s;
	cin >> s;
	for(int i = 0; i < s.size(); i++){
		if(cont.find(s[i]) == cont.end()){
			ans++;
			cont[s[i]]++;
		}
	}
	cout << (ans % 2 ? "IGNORE HIM!\n" : "CHAT WITH HER!\n");
}
