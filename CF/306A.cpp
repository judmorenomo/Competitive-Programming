#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	string s;
	cin >> s;
	bool ab1 = false, ba1 = false, ab2 = false, ba2 = false;
	for(int i = 0; i < s.size()-1; i++){
		if(s[i] == 'A' && s[i+1] == 'B' && !ab1){
			ab1 = true;
			i++;
			continue;
		}
		if(s[i] == 'B' && s[i+1] == 'A' && !ba1 && ab1){
			ba1 = true;
			i++;
			continue;
		}
	}
	for(int i = 0; i < s.size()-1; i++){			
		if(s[i] == 'B' && s[i+1] == 'A' && !ba2){			
			ba2 = true;
			i++;
			continue;
		}
		if(s[i] == 'A' && s[i+1] == 'B' && !ab2 && ba2){
			ab2 = true;
			i++;
			continue;
		}		
	}
	if((ab1 && ba1) || (ab2 && ba2))cout << "YES\n";
	else cout << "NO\n";
}