#include<bits/stdc++.h>
using namespace std;
int valor[3010];
vector<int> vals[3010];
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		int p, c;
		scanf("%d %d", &p, &c);
		p--;
		valor[i] = c;
		vals[p].push_back(c);
	}	
	for(int i = 0; i < m; i++){
		sort(vals[i].begin(), vals[i].end());		
	}
	long long res = LLONG_MAX;
	for(int i = 1; i <= n; i++){		
		int neces = i - vals[0].size();
		long long aux = 0;
		vector<int> sobran;
		for(int p = 1; p < m; p++){			
			int rest = vals[p].size() - (i - 1);
			if(rest < 0)rest = 0;
			for(int j = 0; j < rest; j++){
				aux += vals[p][j];
				neces--;
			}			
			for(int j = rest; j < vals[p].size(); j++){
				sobran.push_back(vals[p][j]);
			}
		}		
		if(neces > 0){
			sort(sobran.begin(), sobran.end());	
			int pos = 0;
			while(neces > 0 && pos < sobran.size()){						
				aux += sobran[pos];
				pos++;
				neces--;
			}					
		}					
		res = min(res, aux);
	}
	printf("%lld\n", res);
}