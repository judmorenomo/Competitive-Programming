#include<bits/stdc++.h>
using namespace std;
int main(){
	vector<int> v;
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		v.push_back(val);
	}
	for(int i = 0; i < n; i++){
		if(v[i] % 2 == 0)v[i]--;
	}
	for(int i = 0; i < n; i++){
		printf("%d ", v[i]);
	}
	puts("");
}