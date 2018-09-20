#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int> ans;
	int n, m, act = 0;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		ans.push_back((val + act) / m);
		act = (act + val) % m;
	}
	for(int i = 0; i < ans.size(); i++){
		printf("%d ", ans[i]);
	}
	puts("");
}