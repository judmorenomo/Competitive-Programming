#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
ld times[1005];
int main(){
	int t, cont = 1;
	scanf("%d", &t);
	while(t--){
		vector<pair<int, int> > road;
		int d, n;
		scanf("%d %d", &d, &n);
		for(int i = 0; i < n; i++){
			int pos, spe;
			scanf("%d %d", &pos, &spe);
			road.push_back({pos, spe});
		}
		times[n] = 0.0;
		sort(road.begin(), road.end());				
		for(int i = n-1; i >= 0; i--){			
			times[i] = max((d - road[i].first) / (ld) road[i].second, times[i+1]);
		}
		printf("Case #%d: %.7Lf\n",cont, fabs(d / times[0]));
		cont++;
	}
}