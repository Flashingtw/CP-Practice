#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n,m;
    cin>>n>>m;
    vector<list<int>> q(n+1);
    while(m--){
        string type;
        cin>>type;
        if(type=="ADD"){
            int i,x;
            cin>>i>>x;
            q[i].push_back(x);
        }
        if(type=="LEAVE"){
            int i;
            cin>>i;
            if(q[i].empty()) cout << "queue "<< i << " is empty!\n";
            else q[i].pop_front();
        }
        if(type=="JOIN"){
            int i,j;
            cin>>i>>j;
            q[j].splice(q[j].end(),q[i]);
        }
    }
    for(int i=1;i<=n;i++){
        cout << "queue "<< i << ": ";
        if(q[i].empty()){
            cout << "empty" << '\n';
            continue;
        }
        for(int a:q[i]){
            cout << a << ' ';
        }
        cout << '\n';
    }
}