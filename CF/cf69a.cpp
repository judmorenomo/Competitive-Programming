#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
	for(int i = 2; i*i <= n; i++){
		if(n % i == 0)return false;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b;
	cin >> a >> b;
	for(int i = a+1; i <= b; i++){
		if(isPrime(i)){
			if(i == b){
				cout << "YES\n";
			}else {
				cout << "NO\n";
			}
			return 0;
		}
	}
	cout << "NO\n";
}
