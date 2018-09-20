#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int> v1, v2;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		v1.push_back(val);
	}
	int m;
	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		int val;
		scanf("%d", &val);
		v2.push_back(val);
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(abs(v1[i]-v2[j]) <= 1){
				v2[j] = 105;
				ans++;
				break;
			}
		}
	}
	printf("%d\n", ans);
}