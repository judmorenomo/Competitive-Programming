#include<bits/stdc++.h>
using namespace std;
bool isPalind(string s){
	int l = 0, r = s.size()-1;
	while(l <= r){
		if(s[l] != s[r])return false;
		l++;
		r--;
	}
	return true;
}
int main(){
	int ans = -1;
	for(int i = 100; i <= 999; i++){
		for(int j = 100; j <= 999; j++){
			int mul = i*j;
			stringstream ss;
			string s;
			ss << mul;
			s = ss.str();
			if(isPalind(s)){				
				ans = max(ans, mul);
			}	
		}
	}
	printf("%d\n", ans);
}