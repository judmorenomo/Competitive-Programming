#include<bits/stdc++.h>
using namespace std;
map<string, int> m;
vector<vector<int> > graf;
vector<string> aux;
bool vis[205];
int dist[205];

bool comp(string a, string b){
	if(a.size() != b.size())return 0;
	int dif = 0;
	for(int i = 0; i < a.size(); i++){
		if(a[i] != b[i])dif++;
	}
	return (dif == 1) ? 1 : 0;
}
int main(){
	//freopen("in.txt", "r", stdin);
	int t;
	bool flag = false;
	scanf("%d", &t);
	string s, word;
	getline(cin, s);
	cin.ignore();
	while(t--){		
		graf.clear();
		aux.clear();
		m.clear();
		int cont = 0;
		while(true){
			getline(cin, word);
			if(word == "*")break;
			aux.push_back(word);
			m[word] = cont;
			cont++;			
		}		
		graf.assign(cont, vector<int>());
		for(int i = 0; i < cont; i++){
			for(int j = i+1; j < cont; j++){				
				if(comp(aux[i], aux[j])){
					graf[m[aux[i]]].push_back(m[aux[j]]);
					graf[m[aux[j]]].push_back(m[aux[i]]);
				}
			}
		}		
		if(!flag)flag = true;
		else puts("");
		while(true){
			getline(cin, word);
			if(word.size() == 0)break;
			stringstream ss(word);
			string word1, word2;
			ss >> word1;
			ss >> word2;
			int sou = m[word1], des = m[word2];
			memset(vis, 0, sizeof vis);
			memset(dist, 0, sizeof dist);
			queue<int> q;
			vis[sou] = 1;
			dist[sou] = 0;
			q.push(sou);
			while(!q.empty()){
				int u = q.front(); q.pop();
				if(u == des)break;
				for(int i = 0; i < graf[u].size(); i++){
					int v = graf[u][i];
					if(!vis[v]){
						vis[v] = 1;
						dist[v] = dist[u]+1;
						q.push(v);
					}
				}
			}
			cout << word1<<" "<<word2<<" "<<dist[des]<<'\n';
		}
	}
}