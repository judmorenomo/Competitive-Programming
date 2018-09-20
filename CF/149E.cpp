#include<bits/stdc++.h>
using namespace std;
const int N_MAX = 200000;
int b[N_MAX], posIzq[N_MAX], posDer[N_MAX], m;
string P;
void pre(){
	int i = 0, j = -1; b[0] = -1;
	while(i < m){
		while(j >= 0 && P[i] != P[j]) j = b[j];
		i++; j++;
		b[i] = j;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	string prin, reve, prinAux, reveAux;
	cin >> prin;
	int tama = prin.size(), ans = 0;
	reve = prin;
	reverse(reve.begin(), reve.end());
	int n; cin >> n;
	while(n--){
		prinAux = prin;
		reveAux = reve;
		string word, word2, aux;
		cin >> word;		
		int tam = word.size();
		if(tam == 1 || tam > tama)continue;
		word2 = word;
		reverse(word2.begin(), word2.end());
		prinAux = word.substr(0, word.size()-1) + "#" + prinAux;		
		reveAux = word2.substr(0, word.size()-1) + "#" + reveAux;		

		P = prinAux;
		m = P.size();
		memset(posIzq, -1, sizeof posIzq);
		memset(posDer, -1, sizeof posDer);
		pre();		
		for(int i = tam; i <= m; i++){
			int valor = b[i];
			if(valor == 0)continue;
			int pos = i - tam;
			if(pos - valor + 1 >= 0 && posIzq[valor] == -1){
				posIzq[valor] = pos - valor + 1;
			}
		}

		P = reveAux;
		m = P.size();
		pre();		
		for(int i = tam; i <= m; i++){
			int valor = b[i];
			if(valor == 0)continue;	
			int pos = i - (tam+1);
			pos = tama - pos;
			if(posDer[valor] == -1){
				posDer[valor] = pos;
			}			
		}		
		for(int i = 1; i < tam; i++){
			if(posIzq[i] == -1 || posDer[tam-i] == -1)continue;
			int hasta = posIzq[i] + i - 1;			
			if(posDer[tam-i] > hasta){						
				ans++;
				break;
			}
		}				
	}
	cout << ans<<'\n';
}