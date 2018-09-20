#include<bits/stdc++.h>
using namespace std;

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	int t;
	cin >> t;
	cin.ignore();
	while(t--){
		string t, p, ss, rev;
		getline(cin, t);
		getline(cin, p);
		int d;
		cin >> d;		
		cin.ignore();
		ss = p + "#" + t;
		reverse(p.begin(), p.end());
		reverse(t.begin(), t.end());
		rev = p + "#" + t;
		vector<int> resRev = z_function(rev);
		vector<int> res = z_function(ss);		
		vector<int> revR(t.size());	
		vector<int> norR(t.size());	
		for(int i = p.size()+1; i < resRev.size()-p.size()+1; i++){
			int pos = i - (p.size()+1) + p.size()-1;
			pos = t.size()-1-pos;
			revR[pos] = resRev[i];			
		}		

		for(int i = p.size()+1; i < res.size()-p.size()+1; i++){
			int pos = i - (p.size()+1);
			norR[pos] = res[i];			
		}				
		int ans = 0;
		for(int i = 0; i < t.size()-p.size()+1; i++){
			int val = revR[i] + norR[i];
			val = p.size()-val;
			if(val <= d)ans++;						
		}
		cout << ans<<'\n';		
	}
}