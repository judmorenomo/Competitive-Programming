#include<bits/stdc++.h>
using namespace std;
string s;
int find(string p){		
	int cont = 0;
	for(int i = 0; i < s.size() - p.size() + 1; i++){		
		if(s[i] == p[0]){
			string sub = s.substr(i, p.size());
			if(sub == p){
				cont++;
			}
		}
	}
	return cont;
}
int main(){	
	getline(cin, s);
	int cont = 0;
	if(s.size() >= 5)cont += find("Danil");
	if(s.size() >= 4)cont += find("Olya");
	if(s.size() >= 5)cont += find("Slava");
	if(s.size() >= 3)cont += find("Ann");
	if(s.size() >= 6)cont += find("Nikita");	
	if(cont == 1){
		puts("YES");
	}else puts ("NO");
}