#include<bits/stdc++.h>
using namespace std;
bool valid(int num, int sum){
	return sum >= 0 && sum <= num*9;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int m, s;
	cin >> m >> s;
	string men = "", may = "";
	int aux = s;
	bool yes1 = true, yes2 = true;
	for(int i = 0; i < m; i++){
		bool auxi = false;
		for(int j = 0; j < 10; j++){
			if((i > 0 || j > 0 || (m == 1 && j == 0)) && valid(m-i-1, aux - j)){
				auxi = true;
				men += (char)(j + '0');
				aux -= j;
				break;
			}
		}
		if(!auxi)yes1 = false;
	}			
	int aux2 = s;
	for(int i = 0; i < m; i++){
		bool auxi = false;
		for(int j = 9; j >= 0; j--){
			if((i > 0 || j > 0 || (m == 1 && j == 0)) && valid(m-i-1, aux2 - j)){
				may += (char)(j + '0');
				aux2 -= j;
				auxi = true;
				break;
			}
		}
		if(!auxi)yes2 = false;
	}
	if(yes1){
		cout << men<<" ";
	}else cout << "-1 ";
	if(yes2){
		cout << may<<'\n';
	}else cout << "-1\n";
}