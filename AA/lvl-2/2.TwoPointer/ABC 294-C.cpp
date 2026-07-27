#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    for(int &x:a) cin>>x;
    for(int &x:b) cin>>x;
    int j=0;
    vector<int> c;
    vector<int> idx_a(n),idx_b(m);
    for(int i=0;i<n;i++){
        while(j<m&&a[i]>b[j]){
            c.push_back(b[j]);
            idx_b[j++] = c.size();
        }
        c.push_back(a[i]);
        idx_a[i]=c.size();
    }
    while(j<m){
        c.push_back(b[j]);
        idx_b[j++] = c.size();
    }
    for(int i:idx_a) cout << i << ' ';
    cout << '\n';
    for(int i:idx_b) cout << i << ' ';
}