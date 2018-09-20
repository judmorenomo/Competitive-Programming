#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > graf;
bool vis[26][26], vis2[26];
int act;

void dfs(int u){	
	vis[act][u] = 1;
	vis2[u] = 1;
	for(int i = 0; i< graf[u].size(); i++){
		if(!vis2[graf[u][i]]){
			dfs(graf[u][i]);
		}
	}		
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int n, m;
	graf.assign(26, vector<int>());
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		char c1, c2;
		cin >> c1 >> c2;
		int val1 = c1-'a', val2 = c2-'a';
		graf[val1].push_back(val2);
	}
	for(int i = 0; i < 26; i++){		
		memset(vis2, 0, sizeof vis2);
		act = i;
		dfs(i);
	}

	for(int i = 0; i < m; i++){
		string word1, word2;
		cin >> word1 >> word2;
		if(word1.size() != word2.size())cout << "no\n";
		else{
			bool pos = true;
			for(int j = 0; j < word1.size(); j++){
				int val1 = word1[j]-'a', val2 = word2[j]-'a';
				if(!vis[val1][val2]){
					pos = false;
					break;
				}
			}
			if(pos)cout << "yes\n";
			else cout << "no\n";
		}	
	}

}
