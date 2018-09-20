#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	getline(cin, s);
	set<char> se;
	if(s.size() == 2){
		puts("0");
		return 0;
	}
	for(int i = 1; i < s.size(); i += 3){
		se.insert(s[i]);
	}	
	cout << se.size()<<'\n';
}