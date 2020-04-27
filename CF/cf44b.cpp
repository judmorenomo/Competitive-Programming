#include<bits/stdc++.h>
using namespace std;

int com[3];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i = 0; i < 3; i++){
		string comp;
		cin >> comp;
		int pos1 = comp[0] - 'A', pos2 = comp[2] - 'A';
		if(comp[1] == '<')com[pos2]++;
		else com[pos1]++;
	}
	string ans = "ABC";
	for(int i = 0; i < 3; i++){
		bool val = false;
		for(int j = 0; j < 3; j++){
			if(com[j] == i){
				ans[i] = (j+'A');
				val = true;
			}
		}
		if(!val){
			ans = "Impossible";
			break;
		}
	}
	cout << ans<<'\n';
}