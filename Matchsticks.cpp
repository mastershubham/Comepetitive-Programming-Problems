#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 100'001;
const int LOG = 17;
int b[MAX_N];
int r_min_q[MAX_N][LOG];
int r_max_q[MAX_N][LOG];
int bin_log[MAX_N];

int min_query(int l,int r){
    int range = r-l+1;
    int j = bin_log[range];
    return min(r_min_q[l][j],r_min_q[r+1-(1<<j)][j]);
}

int max_query(int l,int r){
    int range = r-l+1;
    int j = bin_log[range];
    return max(r_max_q[l][j],r_max_q[r+1-(1<<j)][j]);
}

int main(){
    int n;
    cin>>n;
    bin_log[1] = 0;
    for(int i = 2;i<=n;i++){
        bin_log[i] = bin_log[i/2] + 1;
    }

    for(int i = 0;i<n;i++){
        cin>>b[i];
        r_min_q[i][0] = b[i];
        r_max_q[i][0] = b[i];
    }

    for(int j = 1;j<LOG;j++){
        for(int i = 0;i-1+(1<<j)<n;i++){
            r_min_q[i][j] = min(r_min_q[i][j-1],r_min_q[i+(1<<(j-1))][j-1]);
            r_max_q[i][j] = max(r_max_q[i][j-1],r_max_q[i+(1<<(j-1))][j-1]);
        }
    }

    int q;
    cin>>q;
    while(q--){;
        int l,r;
        cin>>l>>r;
        int range_min = min_query(l,r);
        int range_max = max_query(l,r);
        int left = 0;int right = 0;
        if(l != 0){left = max_query(0,l-1);}
        if(r != n-1){right = max_query(r+1,n-1);}
        double time = range_min;
        double addend = (range_max-range_min)/2.0;
        addend = max(left*1.0,addend);
        addend = max(right*1.0,addend);
        cout<<fixed<<setprecision(1)<<time+addend<<'\n';  
    }
}
