#include<bits/stdc++.h>
using namespace std;
int main(){
	long long val = 20;	
	while(true){
		bool aux = true;
		for(int i = 1; i <= 20; i++){
			if(val % i)aux = false;
		}
		if(aux)break;
		val++;
	}
	printf("%d", val);
}