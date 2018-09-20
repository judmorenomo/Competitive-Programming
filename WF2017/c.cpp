#include<bits/stdc++.h>
using namespace std;
int val[105][105], match[105];
bool vis[105];
vector<vector<int> > graf;
vector<int> fro, sid;
set<int> pesos;

int aug(int u){
	if(vis[u])return 0;
	vis[u] = 1;
	for(int i = 0; i < graf[u].size(); i++){
		int r = graf[u][i];
		if(match[r] == -1 || aug(match[r])){
			match[r] = u; return 1;
		}
	}
	return 0;
}

int main(){	
	int r, c;
	scanf("%d %d", &r, &c);
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			scanf("%d", &val[i][j]);
		}
	}
	for(int j = 0; j < c; j++){
		int may = -1;
		for(int i = 0; i < r; i++){
			may = max(may, val[i][j]);
		}
		fro.push_back(may);
	}
	for(int i = 0; i < r; i++){
		int may = -1;
		for(int j = 0; j < c; j++){
			may = max(may, val[i][j]);
		}
		sid.push_back(may);
	}
	long long sum = 0;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			int x = val[i][j], mayR = sid[i], mayC = fro[j];
			if(x != mayR && x != mayC && x != 0){
				sum += x-1;
				val[i][j] = 1;
			}			
		}
	}	
	for(int i = 0; i < fro.size(); i++)if(fro[i]!= 0)pesos.insert(fro[i]);
	for(int i = 0; i < sid.size(); i++)if(sid[i]!= 0)pesos.insert(sid[i]);

	set<int> :: iterator it;
	for(it = pesos.begin(); it != pesos.end(); it++){
		memset(match, -1, sizeof match);
		int aux = *it;
		graf.assign(105, vector<int>());
		vector<int> left;
		for(int i = 0; i < sid.size(); i++){
			if(sid[i] == aux){
				left.push_back(i);
				for(int j = 0; j < fro.size(); j++){
					if(fro[j] == aux ){						
						if(val[i][j] != 0)graf[i].push_back(j);
					}
				}
			}
		}		
		int res = 0;
		for(int i = 0; i < left.size(); i++){
			memset(vis, 0, sizeof vis);
			int valA = aug(left[i]);			
			res += valA;
		}
		int contR = 0, contC = 0, contTot = 0;
		for(int i = 0; i < fro.size(); i++)if(fro[i] == aux)contC++;
		for(int i = 0; i < sid.size(); i++)if(sid[i] == aux)contR++;
		for(int i = 0; i < r; i++){
			for(int j = 0; j < c; j++){
				if(val[i][j] == aux)contTot++;
			}
		}
		long long nece = contR+contC-res, teng = contTot;
		sum += (teng-nece)*(aux-1);
	}
	cout << sum<<'\n';
}