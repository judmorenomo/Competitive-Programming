#include<bits/stdc++.h>
using namespace std;
int main(){
	int t, cont = 1;
	scanf("%d", &t);
	while(t--){
		int n, tot = 0;
		vector<pair<int, char> > v;
		vector<string> ans;
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			int val;
			char aux = 'A'+i;
			scanf("%d", &val);
			tot += val;
			v.push_back({val, aux});
		}		
		int conta = 0;
		while(tot > 0){
			string ss = "";
			sort(v.begin(), v.end());			
			int val = v[n-1].first;			
			char c = v[n-1].second;
			v[n-1].first--;
			tot--;
			ss.push_back(c);			
			if(tot % 2){
				int val2 = v[n-2].first;
				char c2 = v[n-2].second;
				v[n-2].first--;
				tot--;
				ss.push_back(c2);
			}
			ans.push_back(ss);
		}
		printf("Case #%d: ", cont);
		for(int i = 0; i < ans.size(); i++){
			cout << ans[i]<<" ";
		}
		cont++;
		puts("");
	}
}