#include<bits/stdc++.h>
using namespace std;
#define MAX_N 1000010
const int mod = 1e9 + 7;
int T[MAX_N], pert[MAX_N], pots[4*MAX_N];
pair<int, int> posis [MAX_N];
int n;
int RA[MAX_N], tempRA[MAX_N];
int SA[MAX_N], tempSA[MAX_N];
int c[MAX_N];

void countingSort(int k){
	int i, sum, maxi = max(310, n);
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

struct CustomCompare
{
	bool operator()(const int& a, const int& b){
		return RA[a] > RA[b];
	}
};

int main(){
	//freopen("in.txt", "r", stdin);
	int n2;	
	pots[0] = 1;
	for(int i = 1; i < 4*MAX_N; i++){
		pots[i] = (365LL * pots[i-1]) % mod;
	}
	while(scanf("%d", &n2) != EOF){		
		n = 0;
		int sum = 0;
		for(int i = 0; i < n2; i++){
			int k;
			scanf("%d", &k);
			posis[i] = {n, k+n-1};
			sum += k;
			for(int j = 0; j < k; j++){
				int val;
				scanf("%d", &val);
				pert[n] = i;
				T[n++] = val;
			}
			T[n++] = 305;
		}	

		constructSA();		
		priority_queue<int, vector<int>, CustomCompare> pq;
		for(int i = 0; i < n2; i++){
			pq.push(posis[i].first);
		}				
		int res = 0;
		while(sum > 0){		
			int val = pq.top();			
			pq.pop();					
			int valor = ((long long)T[val]*(long long)pots[sum]) % mod;
			res  = (res + valor) % mod;
			int pos = pert[val];		
			if(posis[pos].first + 1 <= posis[pos].second){
				posis[pos].first++;				
				pq.push(posis[pos].first);
			}				
			sum--;		
		}

		printf("%d\n", res);
	}
}