#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    for(int &i:a) cin>>i;
    for(int &i:b) cin>>i;
    int i=0,j=0,cnt=0;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    while(i<n&&j<m){
        if(a[i]*2>=b[j]){
            i++;
            j++;
            cnt++;
        }
        else{
            i++;
        }
    }
    cout << cnt << '\n';
}