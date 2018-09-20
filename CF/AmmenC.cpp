#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int val;
		scanf("%d", &val);
		int valor = val ^ (val-1), res = 0;
		while(valor > 0){
			int mod = valor % 2;
			if(mod == 1)res++;
			valor /= 2;
		}
		printf("%d\n", res);
	}
}