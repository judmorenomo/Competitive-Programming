#include<bits/stdc++.h>
using namespace std;
int main(){
	int v, men = 1000000, dig = -1;
	vector<int> vec;
	vec.push_back(0);
	scanf("%d", &v);
	for(int i = 1; i <= 9; i++){
		int val;
		scanf("%d", &val);
		vec.push_back(val);
		if(val <= men){
			men = val;
			dig = max(dig, i);
		}
	}
	vector<int> res;
	if(v/men == 0){
		puts("-1");
		return 0;
	}
	for(int i = 0; i < (v/men); i++){
		res.push_back(dig);
	}

	int rest = v - (v/men)*vec[dig];
	for(int i = 0; i < res.size(); i++){
		for(int j = 9; j > res[i]; j--){
			if(rest - vec[j] + vec[res[i]] >= 0){
				rest = rest - vec[j] + vec[res[i]];
				res[i] = j;
				break;
			}
		}
	}

	for(int i = 0; i < res.size(); i++){
		printf("%d", res[i]);
	}
	puts("");
}