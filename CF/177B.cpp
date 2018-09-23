#include<bits/stdc++.h>
using namespace std;

int mat[110][110];

int main(){
	int n, m, d;
	scanf("%d %d %d", &n, &m, &d);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			int val; scanf("%d", &mat[i][j]);			
		}
	}

	vector<int> vec;
	int modAct = mat[0][0] % d;
	bool pos = true;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			vec.push_back(mat[i][j]);
			if(!i && !j)continue;
			int val = mat[i][j] % d;
			if(val != modAct){
				pos = false;
				break;
			}			
		}
		if(!pos)break;
	}
	if(!pos){
		puts("-1");
		return 0;
	}

	long long ans = 0;

	sort(vec.begin(), vec.end());
	int val = vec[vec.size()/2];
	for(int i = 0; i < vec.size(); i++){
		if(i == vec.size()/2)continue;
		ans += (abs(val-vec[i]))/d;
	}
	printf("%lld\n", ans);
}