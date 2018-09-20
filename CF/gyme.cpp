#include<bits/stdc++.h>

using namespace std;
long long cont = 0;
long arr[1000010], laux[500010], raux[500010];

void merge(int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1, n2 = r - m;
    
    for(i = 0; i < n1; i++){
        laux[i] = arr[i+l];
    }
    for(j = 0; j < n2; j++){
        raux[j] = arr[j + m + 1];
    }
    
    i=0;
    j=0;
    k=l;

    while(i < n1 && j < n2){                
        if(laux[i] <= raux[j]){            
            arr[k] = laux[i];
            i++;
        }else{            
                            
            arr[k] = raux[j];
            cont += n1-i;            
            j++;           
        }
        k++;
    }
    
    while(i < n1){
        arr[k] = laux[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = raux[j];
        j++;
        k++;
    }    
}
void mergesort(int l, int r){
    if(l < r){
        int m = l + (r-l)/2;
        
        mergesort(l, m);
        mergesort(m+1, r);
        
        merge(l, m, r);
    }
}
int main() {    
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){        
        scanf("%ld", &arr[i]);        
    }
    mergesort(0, n-1);
    int val1 = (3*n)%2;
    int val2 = (7*n + 1) % 2;
    int val3 = cont%2;
    if(val1 == val3){
        puts("Petr");
    }else{
        puts("Um_nik");
    }
    return 0;
}

