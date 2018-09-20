#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, ans = 0;
	cin >> n;
	string a, b;
	cin >> a;
	cin >> b;	
	if(n % 2){
		ans = (a[(n/2)] != b[(n/2)]);
	}	
	vector<set<char> > v;
	for(int i = 0; i < (n/2); i++){
		set<char> s;
		s.insert(a[i]);
		s.insert(b[i]);
		s.insert(a[n-i-1]);
		s.insert(b[n-i-1]);		
		v.push_back(s);
	}
	for(int i = 0; i < v.size(); i++){
		if(v[i].size() == 4){
			ans += 2;
		}else if(v[i].size() == 3){
			ans += 1 + (a[i] == a[n-i-1]);
		}else if(v[i].size() == 2){
			char c1 = a[i], c2 = a[n-i-1], c3 = b[i], c4 = b[n-i-1];
			if(c1 == c2 && c2 == c3 && c1 != c4)ans++;
			if(c1 == c2 && c2 == c4 && c1 != c3)ans++;
			if(c1 == c3 && c3 == c4 && c1 != c2)ans++;
			if(c2 == c3 && c3 == c4 && c2 != c1)ans++;
		}
	}
	cout << ans<<'\n';
}