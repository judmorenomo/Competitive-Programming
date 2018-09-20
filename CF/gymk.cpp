#include<bits/stdc++.h>
using namespace std;
vector<pair<int, int> > vec;
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		vec.push_back({a, b});
	}		
	int res = -1;
	sort(vec.begin(), vec.end());
	for(int i = 0; i < n; i++){
		if(res <= vec[i].second){
			res = vec[i].second;
		}else res = vec[i].first;
	}
	printf("%d\n", res);
}