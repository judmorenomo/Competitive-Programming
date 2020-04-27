#include<bits/stdc++.h>

int last[100010], act[100010];
bool valid[100010];

using namespace std;
int main(){
	memset(valid, 1, sizeof valid);
	memset(last, -1, sizeof last);
	memset(act, -1, sizeof act);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, num = 0;	
	cin >> n;
	for(int i = 0; i < n; i++){
		int val;
		cin >> val;
		if(last[val] == -1 && valid[val]){
			num++;
			last[val] = i;
			act[val] = 0;
		}else if(valid[val]){
			int dist = i - last[val];
			if(act[val] == 0)act[val] = dist;
			else if(dist != act[val]){
				num--;
				valid[val] = 0;
			}
			last[val] = i;
		}
	}
	cout << num<<'\n';
	for(int i = 1; i <= 1e5 + 5; i++){
		if(valid[i] && act[i] != -1){
			cout << i<<" "<<act[i]<<'\n';
		}
	}
}
