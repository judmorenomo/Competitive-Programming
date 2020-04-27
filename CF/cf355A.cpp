#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n, h, ans = 0;
    cin >> n>> h;
    for(int i = 0; i < n; i++){
        int val;
        cin >> val;
        ans++;
        if(val > h)ans++;        
    }
    cout << ans<<'\n';
}