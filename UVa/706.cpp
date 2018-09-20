#include<bits/stdc++.h>
using namespace std;
#define MAX_N 700
string T;
int n;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N];

void countingSort(int k){
	int i, sum, maxi = max(300, n);
	memset(c, 0, sizeof c);
	for(i = 0; i < n; i++)
		c[i + k < n ? RA[i + k] : 0]++;
	for(i = sum = 0; i < maxi; i++){
		int t = c[i]; c[i] = sum; sum += t;
	}
	for(i = 0; i < n; i++)
		tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
	for(i = 0; i < n; i++)
		SA[i] = tempSA[i];
}

void constructSA(){
	int i, k, r;
	for(i = 0; i < n; i++) RA[i] = T[i];
	for(i = 0; i < n; i++) SA[i] = i;
	for(k = 1; k < n; k <<= 1){
		countingSort(k);
		countingSort(0);
		tempRA[SA[0]] = r = 0;
		for(i = 1; i < n; i++)
			tempRA[SA[i]] = 
			(RA[SA[i]] == RA[SA[i-1]] && RA[SA[i] + k] == RA[SA[i-1]+ k]) ? r: ++r;
		for(i = 0; i < n; i++)
			RA[i] = tempRA[i];
		if(RA[SA[n-1]] == n-1)break;
	}
}

int Phi[MAX_N], LCP[MAX_N], PLCP[MAX_N];

void computeLCP(){
	int i, L;
	Phi[SA[0]] = -1;
	for(i = 1; i <  n; i++){
		Phi[SA[i]] = SA[i-1];
	}
	for(i = L = 0; i < n; i++){
		if(Phi[i] == -1){PLCP[i] = 0; continue;}
		while(T[i + L] == T[Phi[i] + L])L++;
		PLCP[i] = L;
		L = max(L-1, 0);
	}
	for(i = 0; i < n; i++)
		LCP[i] = PLCP[SA[i]];
}

int main(){			
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	string s, s2;
	bool flag = false;
	while(getline(cin, s)){		
		int tam = s.size();
		s.push_back('$');		
		getline(cin, s2);		
		s += s2;
		s.push_back('#');
		T = s;
		n = T.size();		
		constructSA();
		computeLCP();
		set<string> ans;
		int act = -1;		
		for(int i = 2; i < n; i++){					
			int val = SA[i];
			if(val < tam){		
				if(SA[i-1] < tam)continue;						
				string sub = s.substr(SA[i], LCP[i]);				
				if(LCP[i] == act){
					ans.insert(sub);
				}else if(LCP[i] > act){					
					act = LCP[i];
					ans.clear();
					ans.insert(sub);
				}				
			}else{
				if(SA[i-1] >= tam)continue;
				string sub = s.substr(SA[i], LCP[i]);				
				if(LCP[i] == act){				
					ans.insert(sub);
				}else if(LCP[i] > act){					
					act = LCP[i];
					ans.clear();
					ans.insert(sub);
				}				
			} 
		}		
		if(flag){
			cout << '\n';
		}else flag = true;
		if(act == 0){
			cout << "No common sequence.\n";
		}else{
			set<string> :: iterator it;
			for(it = ans.begin(); it != ans.end(); it++){
				cout << *it<<'\n';
			}	
		}		
		string nada;
		getline(cin, nada);
	}	
}