#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m);
    for(int &i:a) cin>>i;
    for(int &i:b) cin>>i;
    
    int i=0,j=0;
    for(int i=0;i<n;i++){
        if(a[i]==b[j]){
            j++;
        }
    }
    if(j==m) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}