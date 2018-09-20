#include<bits/stdc++.h>
using namespace std;
int cont1[30], cont2[30];
vector<int> ans;
string s, t;
void solve(int pos){
	int aux = pos;
	while(s[aux] != t[pos]){
		aux++;
	}	
	for(int i = aux; i > pos; i--){
		swap(s[i], s[i-1]);
		ans.push_back(i);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	memset(cont1, 0, sizeof cont1);
	memset(cont2, 0, sizeof cont2);
	int n;
	cin >> n;	
	cin >> s >> t;
	for(int i = 0; i < n; i++){
		cont1[s[i] - 'a']++;
		cont2[t[i] - 'a']++;
	}
	bool yes = true;
	for(int i = 0; i < 26; i++){
		if(cont1[i] != cont2[i]){
			yes = false;
			break;
		}
	}
	if(!yes){
		cout << "-1\n";
		return 0;
	}
	for(int i = 0; i < n; i++){
		if(s[i] != t[i])solve(i);		
	}
	cout << ans.size()<<'\n';
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i]<<" ";
	}
	cout <<'\n';
}