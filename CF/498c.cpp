#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int n;

int main(){
	set<long long> s;
	long long sum = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		sum += val;
		s.insert(sum);
		v.push_back(val);
	}		
	long long ans = 0, aux = 0;
	for(int i = n-1; i >= 0; i--){
		s.erase(sum);
		sum -= v[i];
		aux += v[i];
		if(s.count(aux))ans = max(ans, aux);
	}	
	printf("%I64d\n", ans);
}