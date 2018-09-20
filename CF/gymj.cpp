#include<bits/stdc++.h>
using namespace std;
int b[2010], n, m, auxP, auxT;
string p, t;
bool matriz[]
map<int, set<pair<int, int> > > ma;
void pre(){		
	int i = 0, j = -1; b[0] = -1;
	while(i < m){
		while(j >= 0 && p[i] != p[j]) j = b[j];
		i++;j++;
		b[i] = j;
	} 
}

void kmp(){
	int i = 0, j = 0;
	while(i < n){
		while(j >= 0 && t[i] != p[j])j = b[j];
		i++; j++;
		if(j == m){
			ma[auxP].insert({auxT, i-j});			
			j = b[j];
		}
	}
}
int main(){
	vector<string> prime, segu;
	int r, c;
	scanf("%d %d", &r, &c);
	m = c;
	n = r;	
	for(int i = 0; i < r; i++){
		string s;
		cin >> s;
		prime.push_back(s);
	}
	for(int i = 0; i < c; i++){
		string s;
		cin >> s;
		segu.push_back(s);
	}		

	for(int i = 0; i < prime.size(); i++){			
		auxP = i;
		p = prime[i];	
		pre();						
		for(int j = 0; j < segu.size(); j++){
			auxT = j;
			t = segu[j];
			kmp();
		}
	}
	bool res = false;
	int ini = -1, fin = -1;
	for(int i = 0; i <= prime.size() - c; i++){				
		set<pair<int, int> > se = ma[i];
		set<pair<int, int> > :: iterator it;
		for(it = se.begin(); it != se.end(); it++){
			pair<int, int> valor = {it-> first, it -> second};			
			int iniAux = valor.first;
			int j;
			for(j = 1; j < c; j++){
				pair<int, int> buscar = {iniAux+j, valor.second};						
				if(ma[i+j].find(buscar) == ma[i+j].end())break;							
			}
			if(j == c){
				res = true;
				ini = iniAux;
				fin = valor.second;
				break;
			}			
		}	
		if(res)break;
	}

	printf("%d %d\n", ini+c-1, fin+1);
}