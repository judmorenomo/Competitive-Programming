#include<bits/stdc++.h>
using namespace std;
set<pair<int, int> > s;

int main(){
	int t;
	scanf("%d", &t);	
	while(t--){
		s.clear();
		int a;
		scanf("%d", &a);
		int fil = 2, col = 2;		
		while(true){
			cout << fil<<" "<<col<<endl;
			int val1, val2;
			scanf("%d %d", &val1, &val2);
			s.insert({val1, val2});
			if(!val1 && !val2)break;
			if(s.size() % 9 == 0)col += 3;
		}
	}
}