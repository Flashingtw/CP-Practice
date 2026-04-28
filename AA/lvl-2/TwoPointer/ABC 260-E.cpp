#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
int cnt[N];
vector<int> d[N];
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        d[a].push_back(i);
        d[b].push_back(i);
    }
    int cur=0;
    vector<int> diff(m+5);
    // [l,r) l到r-1為起點l到最小的可包含全部東西的距離
    for(int l=1,r=1;l<=m;l++){
        while(cur<n&&r<=m){
            for(int a:d[r]){
                if(cnt[a]++==0) cur++;
            }
            r++;
        }
        if(cur==n){
            diff[r-l]++;
            diff[m-l+2]--;
        }
        for(int a:d[l]){
            if(--cnt[a]==0) cur--;
        }
    }
    int c=0;
    for(int i=1;i<=m;i++){
        c += diff[i];
        cout << c << ' ';
    }
}