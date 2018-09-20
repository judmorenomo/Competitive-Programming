#include<bits/stdc++.h>
using namespace std;
int arr[2005];
int main(){
	int n, k;
	vector<int> v1, v2;
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; i++){
		int val;
		scanf("%d", &val);
		v1.push_back(val);
		v2.push_back(val);
	}
	sort(v2.rbegin(), v2.rend());	
	memset(arr, 0, sizeof arr);
	int sum = 0;
	for(int i = 0; i < k; i++){
		sum += v2[i];
		arr[v2[i]]++;
	}	
	int act = 0, aux;
	vector<int> ans;
	for(int i = 0; i < n; i++){		
		act++;
		if(arr[v1[i]] != 0){
			aux = i;
			arr[v1[i]]--;
			ans.push_back(act);
			act = 0;
		}
	}

	if(aux != n-1){
		ans[ans.size()-1] += (n-1)-aux;
	}
	printf("%d\n", sum);
	for(int i = 0; i < ans.size(); i++){
		printf("%d ", ans[i]);
	}
	puts("");
}