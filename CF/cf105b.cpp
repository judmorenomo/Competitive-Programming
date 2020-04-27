#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	double vp, vd, t, f, c, dv;
	cin >> vp >> vd >> t >> f >> c;
	dv = vd-vp;
	if(vp >= vd)cout << "0";
	else {
		double pos = 0;
		int ans = 0;
		pos = vp*t;
		while(pos < c){			
			double val = pos/dv;
			pos += vp*val;	
			if(pos >= c)break;		
			ans++;
			double bac = (pos)/vd;	
			pos += bac*vp;
			pos += f*vp;
		}		
		cout << ans<<'\n';
	}
}
