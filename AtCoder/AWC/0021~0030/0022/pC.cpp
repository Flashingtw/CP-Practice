#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
ll diff[N],prefix[N];
int main(){
    int n,m,k,t;
    cin>>n>>m>>k>>t;
    for(int i=0;i<m;i++){
        int b;
        cin>>b;
        diff[b]++;
    }
    for(int i=1;i<=n;i++){
        prefix[i]=prefix[i-1]+diff[i];
    }
    for(int i=0;i<k;i++){
        int l,r;
        cin>>l>>r;
        if(prefix[r]-prefix[l-1]>=t){
            cout << "YES" << '\n';
        }
        else cout << "NO" << '\n';
    }
}