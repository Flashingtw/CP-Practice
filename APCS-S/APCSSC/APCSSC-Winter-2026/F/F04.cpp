#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0),cin.tie(0);
    int n,k,q;
    cin>>n>>k>>q;
    vector<int> v(n,k-q);
    while (q--) {
        int val;
        cin>>val;
        val--;
        v[val]++;
    }
    for (int i : v) cout << (i>0?"Yes":"No") << "\n";
}