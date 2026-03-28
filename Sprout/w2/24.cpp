#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<list<int>> q(n+1);
    while(m--){
        string s;
        cin>>s;
        if(s[0]=='A'){
            int i,id;
            cin>>i>>id;
            q[i].push_back(id);
        }
        else if (s[0]=='L'){
            int i;
            cin>>i;
            if(q[i].empty()){
                cout << "queue " << i << " is empty!\n";
            }
            else{
                q[i].pop_front();
            }
        }
        else {
            int i,j;
            cin>>i>>j;
            q[j].splice(q[j].end(),q[i]);
        }
    }
    for(int i=1;i<=n;i++){
        cout << "queue " << i << ": ";
        if(q[i].empty()){
            cout << "empty\n";
            continue;
        }
        for(auto it=q[i].begin();it!=q[i].end();it++){
            if(it==q[i].begin()) cout << *it;
            else cout << ' ' << *it;
        }
        cout << '\n';
    }
}