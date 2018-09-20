#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, cont = 0;
	vector<int> v;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		if(val == 1){
			cont++;
			v.push_back(i);
		}
	}
	v.push_back(n);
	printf("%d\n", cont);
	for(int i = 0; i < v.size() - 1; i++){
		printf("%d ", v[i+1]-v[i]);
	}
}