#include<bits/stdc++.h>
using namespace std;
#define eps 1e-9
int aux[10010];
bool cmp(pair<int, int> a, pair<int, int> b){
	return (a.first*b.second < a.second*b.first);	
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		memset(aux, 0, sizeof aux);
		set<int> ss;
		int n;
		scanf("%d", &n);
		for(int i = 0; i <n; i++){
			int val;
			scanf("%d", &val);
			aux[val]++;
			ss.insert(val);
		}
		bool flag = false;
		vector<int> vals;
		set<int> :: iterator it;		
		for(it = ss.begin(); it != ss.end(); it++){			
			if(aux[*it] > 3){
				vals.push_back(*it);
				vals.push_back(*it);
			}else if(aux[*it] > 1)vals.push_back(*it);
		}
		if(flag)continue;
		sort(vals.begin(), vals.end());
		double ans = DBL_MAX;
		int ans1, ans2;
		if(vals.size() == 1){
			printf("%d %d %d %d\n", vals[0], vals[0], vals[0], vals[0]);
			return 0;
		}
		vector<pair<int, int> > res;
		for(int i = 0; i < vals.size()-1; i++){
			res.push_back({vals[i+1], vals[i]});
		}
		sort(res.begin(), res.end(), cmp);
		printf("%d %d %d %d\n", res[0].first, res[0].first, res[0].second, res[0].second);

	}
}