#include<bits/stdc++.h>
using namespace std;
int main(){
	for(int i = 1; i <= 1000; i++){
		for(int j = i+1; j <= 1000; j++){
			for(int k = j+1; k <= 1000; k++){
				if(i+j+k == 1000 && (i*i + j*j == k*k)){

					cout << i<<" "<<j<<" "<<k<<'\n';
				}
			}
		}
	}
}