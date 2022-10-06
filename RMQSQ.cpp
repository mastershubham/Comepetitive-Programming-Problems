#include <bits/stdc++.h>
using namespace std;
typedef long long int;

const int MAX_N = 100000;
const int LOG = 20;
int a[MAX_N];
int mem[MAX_N][LOG];
int bin_log[MAX_N];

int query(int l,int r){
    int range = r-l+1;
    int j = bin_log[range];
    return min(mem[l][j],mem[r+1-(1<<j)][j]);
}
int main(){
    int n;
    cin>>n;
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
            mem[i][j] = min(mem[i][j-1],mem[i+(1<<(j-1))][j-1]);
        }
    }

    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<query(l,r)<<'\n';
    }
}
