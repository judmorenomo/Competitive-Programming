#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	vector<int> v;
	long long sum = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		v.push_back(val);
		sum += val;
	}
	int pos = 0;
	long long sum2 = 0;
	for(int i = 0; i < v.size(); i++){
		sum2+=v[i];
		if(sum2*2 >= sum){
			pos = i;
			break;
		}
	}
	printf("%d\n", pos+1);
}