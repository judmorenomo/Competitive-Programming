#include<bits/stdc++.h>
using namespace std;

string valor(int n){	
	string ans = "";
	while(n){
		int val = n % 10;
		if(val){
			ans += '1';
		}else ans += '0';
		n /= 10;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
int main(){
	vector<int> ans;
	int n;
	scanf("%d", &n);
	while(n){
		string s = valor(n);		
		stringstream ss(s);
		int val;
		ss >> val;
		ans.push_back(val);
		n -= val;
	}
	printf("%d\n", ans.size());
	for(int i = 0; i < ans.size(); i++){
		printf("%d ", ans[i]);
	}
	puts("");
}