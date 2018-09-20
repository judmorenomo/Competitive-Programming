#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int t, cont = 1;
	scanf("%d", &t);
	while(t--){
		map<ll, ll> segs;
		ll n, k;
		scanf("%lld %lld", &n, &k);
		segs[n] = 1;
		ll left = -1, right = -1;
		while(k > 0){
			map<ll, ll> :: iterator it = prev(segs.end());
			ll tam = it->first, num = it->second;
			segs.erase(it);
			left = tam/2, right = (tam-1)/2;
			segs[left] += num, segs[right] += num;					
			k -= num;
		}
		printf("Case #%d: %lld %lld\n",cont, max(left, right), min(left, right));
		cont++;	
	}
}