#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> a(n),b(m);
    for(int &i:a) cin>>i;
    for(int &i:b) cin>>i;
    int i=0,j=0;
    while(i<n&&j<m){
        if(a[i]<b[j]){
            cout << 'A';
            i++;
        }
        else {
            cout << 'B';
            j++;
        }
    }
    while(i<n) {
        i++;
        cout << 'A';
    }
    while(j<m){
        j++;
        cout << 'B';
    }
}