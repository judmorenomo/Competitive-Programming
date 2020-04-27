#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int l = 0, u = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= 'a' && s[i] <= 'z')l++;
		else u++;
	}
	if( l >= u){
		for(int i = 0; i < s.size(); i++){
			cout << (char)tolower(s[i]);
		}
	}else{
		for(int i = 0; i < s.size(); i++){
			cout << (char)toupper(s[i]);
		}
	}
}
