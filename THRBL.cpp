#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 50001;
const int LOG = 16;
int a[MAX_N];
int mem[MAX_N][LOG];
int bin_log[MAX_N];

int query(int l,int r){
    int range = r-l+1;
    int j = bin_log[range];
    return max(mem[l][j],mem[r+1-(1<<j)][j]);
}
int main(){
    int n,m;
    cin>>n>>m;
    bin_log[1] = 0;
    for(int i = 2;i<=n;i++){
        bin_log[i] = bin_log[i/2] + 1;
    }

    for(int i = 0;i<n;i++){
        cin>>a[i];
        mem[i][0] = a[i];
    }

    for(int j = 1;j<LOG;j++){
        for(int i = 0;i-1+(1<<j)<n;i++){
            mem[i][j] = max(mem[i][j-1],mem[i+(1<<(j-1))][j-1]);
        }
    }
    int count = 0;
    while(m--){
        int A,B;
        cin>>A>>B;
        A--;B--;
        int range_max = query(A,B-1);
        if(range_max == a[A]){count++;}
    }
    cout<<count<<"\n";
}
