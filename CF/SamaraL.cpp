#include<bits/stdc++.h>
using namespace std;
#define LIM 200005;
vector<vector<int> > inds;
int main(){	
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	string s;
	cin >> s;
	inds.assign(30, vector<int>());
	for(int i = 0; i < s.size(); i++){
		 int val = s[i]-'a';
		 inds[val].push_back(i);
	}	
	vector<int> linds;
	vector<bool> ans;
	int numQ;
	cin >> numQ;
	while(numQ--){
		string o;
		cin >> o;		
		bool pos = true;
		if(o == "push"){
			char c;
			cin >> c;
			int act = -1;
			if(!linds.empty())act = linds.back();
			int val = c-'a';
			vector<int>::iterator it = upper_bound(inds[val].begin(), inds[val].end(), act);
			if(it == inds[val].end()){
				linds.push_back(200005);
				pos = false;				
			}else{
				linds.push_back(*it);
			}
			ans.push_back(pos);
		}else{
			linds.pop_back();
			ans.pop_back();
			if(!ans.empty())pos = ans.back();
		}
		if(pos)cout << "YES\n";
		else cout << "NO\n";		
	}
}