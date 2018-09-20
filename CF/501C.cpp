#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	long long sum1 = 0, sum2 = 0;
	vector<int> vec;
	for(int i = 0; i < n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		sum1 += a;
		sum2 += b;		
		vec.push_back(a - b);
	}
	if(sum1 <= m){
		puts("0");
		return 0;
	}
	if(sum2 > m){
		puts("-1");
		return 0;
	}
	int ans = 0, pos = 0;
	sort(vec.rbegin(), vec.rend());	
	while(sum1 > m){
		sum1 -= vec[pos];
		pos++;
		ans++;
	}
	printf("%d\n", ans);
}