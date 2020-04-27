#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    string s;
    cin >> n;
    cin >> s;
    int a = 0, d = 0;
    for(int i = 0; i< s.length(); i++){
        if(s[i] == 'A')a++;
        else d++;
    }
    if(a > d)cout << "Anton\n";
    else if(d > a)cout << "Danik\n";
    else cout << "Friendship\n";
}