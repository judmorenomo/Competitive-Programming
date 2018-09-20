#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > vec;
vector<int> vals, ans;
int main(){
	int t, caso = 1;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		vec.clear();
		vals.clear();
		ans.clear();
		vec.assign(3, vector<int>());
		for(int i = 0; i < n; i++){
			int val;
			scanf("%d", &val);
			vals.push_back(val);
			vec[i % 2].push_back(val);
		}	
		for(int i = 0; i < 3; i++){
			sort(vec[i].begin(), vec[i].end());
		}
		sort(vals.begin(), vals.end());
		int cont = 0, auxVec = 0, posImp = 0;	
		while(cont < n){		
			ans.push_back(vec[auxVec][posImp]);
			auxVec++;
			if(auxVec == 2){
				auxVec = 0;
				posImp++;
			}
			cont++;
		}

		if(vals == ans){
			printf("Case #%d: OK\n", caso);
		}else{
			int pos = 0;
			for(int i = 0; i < vals.size(); i++){
				if(vals[i] != ans[i]){
					pos = i;
					break;
				}
			}
			printf("Case #%d: %d\n", caso, pos);
		}
		caso++;
	}
}