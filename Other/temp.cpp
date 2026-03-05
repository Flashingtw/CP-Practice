#include <bits/stdc++.h>

using namespace std;


void solve() {
    int n;
    cin>>n;
    vector<int> team_id(1000005,1001);
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        while (k--) {
            int m;
            cin >> m;
            team_id[m] = i;
        }
    }

    queue<int> mas;
    queue<int> team_qs[1005];
    vector<bool> inmas(1005,0);


    int query;
    cin>>query;
    while (query--) {
        string cmd;
        cin>>cmd;
        if (cmd == "ENQUEUE") {
            int x;
            cin >> x;
            int t = team_id[x];

            if (!inmas[t]&&t!=1001) {
                mas.push(t);
                inmas[t] = true;
            }
            if(t==1001){
                mas.push(t);                
            }
            team_qs[t].push(x);
        }
        else if (cmd == "DEQUEUE") {
            int t = mas.front();
            cout << team_qs[t].front() << "\n";
            team_qs[t].pop();
            if (team_qs[t].empty()||t==1001) {
                mas.pop();
                inmas[t] = false;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++) {
        cout << "Line #" << i << "\n";
        solve();
    }
}