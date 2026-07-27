#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n;
    cin>>n;
    unordered_map<int,list<int>::iterator> ptr;
    list<int> ls;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        ls.push_back(a);
        ptr[a] = prev(ls.end());
    }
    int q;
    cin>>q;
    while(q--){
        int t;
        cin>>t;
        if(t==1){
            int x,y;
            cin>>x>>y;
            ptr[y] = ls.insert(next(ptr[x]),y);
        }
        else{
            int x;
            cin>>x;
            ls.erase(ptr[x]);
        }
    }
    for(int i:ls) cout << i << ' ';
}