#include<bits/stdc++.h>
using namespace std;
bool primo(int n){
	for(int i = 2; i*i <= n; i++){
		if(n % i == 0)return 0;
	}
	return 1;
}
int main(){
	for(int i = 1000000000; i >= 0; i--){
		if(primo(i)){
			cout << i<<'\n';
			break;
		}
	}
}