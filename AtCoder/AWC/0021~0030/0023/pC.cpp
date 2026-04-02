#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
ll prefix[N];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int num;
        cin>>num;
        prefix[i]=prefix[i-1]+num;
    }
    for(int i=0;i<m;i++){
        int s,l,r;
        cin>>s>>l>>r;
        cout << s+(prefix[r]-prefix[l-1]) << '\n';
    }
}