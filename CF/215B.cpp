#include<bits/stdc++.h>
using namespace std;
bool arr[100010];
int pos[100010];
int main(){
	vector<int> v;
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		v.push_back(val);
	}
	pos[n-1] = 1;
	arr[v[n-1]] = 1;
	for(int i = n-2; i >= 0; i--){
		int val = v[i];
		if(!arr[val]){
			arr[val] = 1;	
			pos[i]++;		
		}
		pos[i] += pos[i+1];
	}
	for(int i = 0; i < m; i++){
		int x;
		scanf("%d", &x);
		x--;
		printf("%d\n", pos[x]);
	}
}