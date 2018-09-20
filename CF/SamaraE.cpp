#include<bits/stdc++.h>
using namespace std;
int main(){
	string s1, s2;
	cin >> s1;
	cin >> s2;	
	int pri = -1, ult = -1;
	for(int i = 0; i < s1.size(); i++){
		if(s1[i] != s2[i]){
			if(pri == -1){
				pri = i;
			}else ult = i;
		}
	}		
	if(pri == -1 ){
		cout << "YES\n";
	}else if(ult == -1){
		cout << "NO\n";
	}else{
		string aux1 = s1.substr(pri, ult-pri+1);
		string aux2 = s2.substr(pri, ult-pri+1);
		reverse(aux2.begin(), aux2.end());		
		if(aux1 == aux2){
			cout << "YES\n";
		}else cout << "NO\n";
	}
	
}