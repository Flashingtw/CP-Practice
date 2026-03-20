#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 2e5+5;
int p[N];
int t[N];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>p[i]>>t[i];
    }
    ll ans=0;
    for(int i=0;i<m;i++){
        int k;
        cin>>k;
        vector<int> veg,meat;
        for(int i=0;i<k;i++){
            int s;
            cin>>s;
            if(t[s]==1){
                meat.push_back(p[s]);
            }
            else veg.push_back(p[s]);
        }
        sort(veg.begin(),veg.end());
        sort(meat.begin(),meat.end());
        if(veg.empty()||meat.empty()){
            cout << -1 << '\n';
        }
        else cout << veg[0]+meat[0] << '\n';
    }
}