#include<bits/stdc++.h>
using namespace std;
long long vals[150010];
map<long long, vector<int> > m;
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		vals[i] = val;
		m[val].push_back(i);
	}
	
	while(!m.empty()){
		map<long long, vector<int> > :: iterator it = m.begin();
		long long valor = it->first;
		vector<int> posi = it->second;
		m.erase(it);
		long long suma = 2*valor;
		sort(posi.begin(), posi.end());
		for(int i = 0; i < posi.size()-1; i+=2){
			m[suma].push_back(posi[i+1]);
			vals[posi[i]] = -1;
			vals[posi[i+1]] = suma;
		}
	}
	int cont = 0;
	vector<long long> res;
	for(int i = 0; i < 150010; i++){
		if(vals[i] != -1 && vals[i] != 0){
			cont++;
			res.push_back(vals[i]);
		}
	}
	printf("%d\n", cont);
	for(int i = 0; i < res.size(); i++){
		printf("%I64d ", res[i]);
	}
	puts("");
}