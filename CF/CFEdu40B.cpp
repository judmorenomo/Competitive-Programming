#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	string s;
	cin >> s;
	int ans = s.size(), tam = s.size();
	for(int i = 0; i < s.size()/2; i++){
		string s1 = s.substr(0, i+1);
		string s2 = s.substr(i+1, i+1);
		if(s1 == s2){
			ans = min(ans, (i+1)+1+tam-2*(i+1));
		}
	}
	printf("%d\n", ans);
	return 0;
}