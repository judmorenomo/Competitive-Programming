#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	vector<int> vec;
	map<int, int> m;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		vec.push_back(val);
		m[val]++;
	}		
	int ans = 0;
	for(int i = 0; i < n; i++){
		bool yes = true;
		for(int j = 0; j <= 30; j++){
			int val = (1 << j);
			val -= vec[i];
			if(m.count(val)){
				if(m[val] > 1 || (m[val] == 1 && val != vec[i])){
					yes = false;
				}
			}
		}
		if(yes){
			ans++;
		}
	}
	printf("%d\n", ans);
}