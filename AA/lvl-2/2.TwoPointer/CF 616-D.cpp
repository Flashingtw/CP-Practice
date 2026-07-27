#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 1e6+5;
int cnt[N];
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int &a:v) cin>>a;
    int l=0,chk=0;
    int mx=0,L=-1,R=-1;
    for(int r=0;r<n;r++){
        if(cnt[v[r]]==0) chk++;
        cnt[v[r]]++;
        while(chk>k){
            if(cnt[v[l]]==1) chk--;
            cnt[v[l++]]--;
        }

        if(r-l+1>mx){
            mx = r-l+1;
            L = l;
            R = r;
        }
    }
    cout << L+1 << ' ' << R+1 << '\n';
}