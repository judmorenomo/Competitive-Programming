#include<bits/stdc++.h>
using namespace std;
int main(){
	string a, b;
	getline(cin, a);
	getline(cin, b);
	int posA = a.size()-1, posB = b.size()-1, res = 0;
	while(posA >= 0 && posB >= 0){		
		if(a[posA] == b[posB]){
			res++;
			posA--;
			posB--;
		}else break;
	}

	printf("%d\n", a.size()+b.size() - 2*res);
}