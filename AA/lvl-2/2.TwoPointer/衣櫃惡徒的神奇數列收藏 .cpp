#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int &a:v) cin>>a;
    map<int,int> cnt;
    int l = 0,mx=0,idxl=-1,idxr=-1;
    for(int r=0;r<n;r++){
        cnt[v[r]]++;
        while(cnt[v[r]]>1){
            cnt[v[l++]]--;
        }

        if(r-l+1 > mx){
            mx = r-l+1;
            idxl = l;
            idxr = r;
        }
    }
    for(int i=idxl;i<=idxr;i++){
        cout << v[i] << ' ';
    }
}