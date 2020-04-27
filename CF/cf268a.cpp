#include<bits/stdc++.h>
using namespace std;

int arr[110];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a, b;
	cin >> a;
	for(int i = 0; i < a; i++){
		int val; cin >> val;
		arr[val] = 1;
	}
	cin >> b;
	for(int i = 0; i < b; i++){
		int val; cin >> val;
		arr[val] = 1;
	}
	bool yes = true;
	for(int i = 1; i <= n; i++){
		if(!arr[i]){
			yes = false;
			break;
		}
	}
	cout << (yes ? "I become the guy.\n" : "Oh, my keyboard!\n");
}
