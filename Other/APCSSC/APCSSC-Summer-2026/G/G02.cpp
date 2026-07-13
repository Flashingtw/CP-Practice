#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
const int N = 1e5;
vector<int> arr[N];

int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        arr[b].push_back(a);
    }
    while(q--){
        int a;
        cin>>a;
        int sz = arr[a].size();
        
        if(sz){
            cout << *arr[a].begin();
            for(int i=1;i<sz;i++) cout << ' ' << arr[a][i];
        }
        cout << '\n';
    }
}