#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	string s, ans = "";
	cin >> s;
	bool yes = false;		
	if(s.size() == 1){
		if(s == "0" || s == "8"){
			cout << "YES\n"<<s<<'\n';			
		}else cout << "NO\n";
		return 0;
	}
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '8' || s[i] == '0'){
			yes = true;
			ans = s[i];
			break;
		}
	}
	if(yes){
		cout << "YES\n"<<ans;
		return 0;
	}

	for(int i = 0; i < s.size()-1; i++){		
		if(s[i] == '0')continue;
		for(int j = i+1; j < s.size(); j++){
			int val = (s[i] - '0')*10 + (s[j] - '0');
			if(val % 8 == 0){
				ans += s[i];
				ans += s[j];
				yes = true;
				break;
			}
		}
		if(yes)break;
	}
	if(yes){
		cout << "YES\n"<<ans;
		return 0;
	}

	for(int i = 0; i < s.size()-2; i++){
		if(s[i] == '0')continue;
		for(int j = i+1; j < s.size()-1; j++){
			for(int k = j+1; k < s.size(); k++){
				int val = (s[i]-'0')*100 + (s[j]-'0')*10 + (s[k]-'0');
				if(val % 8 == 0){
					ans += s[i];
					ans += s[j];
					ans += s[k];
					yes = true;
					break;
				}
			}
			if(yes)break;
		}
		if(yes)break;
	}
	if(yes){
		cout << "YES\n"<<ans;		
	}else cout << "NO\n";
}