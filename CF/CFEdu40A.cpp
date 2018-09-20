#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	string s;
	cin >> s;
	int ans = s.size();
	for(int i = 0; i < s.size()-1; i++){
		if((s[i] == 'U' && s[i+1] == 'R') || (s[i] == 'R' && s[i+1] == 'U')){
			ans--;
			i++;
		}
	}
	printf("%d\n", ans);
	return 0;
}