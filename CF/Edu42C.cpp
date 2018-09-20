#include<bits/stdc++.h>
using namespace std;
vector<string> pots;

bool esta(string act, string pot){
	int pos1 = 0, pos2 = 0;
	while(pos1 < act.size() && pos2 < pot.size()){
		if(act[pos1] == pot[pos2]){
			pos2++;
			pos1++;
		}else{
			pos2++;
		}
	}
	if(pos1 == act.size())return true;
	return false;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	for(int i = 1; i*i <= 2000000000; i++){
		int pot = i*i;
		if(pot > 2000000000)break;		
		stringstream ss;
		string s;
		ss << pot;
		s = ss.str();
		pots.push_back(s);
	}
	cout << pots[pots.size()-1]<<'\n';
	string s;
	int ans = INT_MAX;
	getline(cin, s);
	bool pos = false;
	for(int i = 0; i < pots.size(); i++){
		string act = pots[i];
		if(act.size() > s.size())break;
		if(esta(act, s)){
			pos = true;
			int val = s.size()-act.size();
			ans = min(ans, val);
		}
	}

	if(!pos)cout << "-1\n";
	else{
		cout << ans<<'\n';
	}
}