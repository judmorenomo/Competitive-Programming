#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	vector<string> ans;
	string act = "";
	for(int i = 0; i < s.size(); i++){
		if(i < s.size()-2 && s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B'){
			i += 2;
			if(act != "")ans.push_back(act);
			act = "";
		}
		else {
			act += s[i];
		}
	}
	
	if(act != "")ans.push_back(act);
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i];
		if(i != ans.size()-1)cout << " ";
	}
	cout <<'\n';
}
