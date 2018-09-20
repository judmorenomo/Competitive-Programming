#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d", &n);
	int izq = n-1, cent = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < izq; j++){
			cout << " ";
		}
		cout << "/";
		for(int j = 0; j < cent; j++){
			cout << " ";
		}
		cout << "\\"<<'\n';
		izq--;
		cent += 2;
	}		
}