#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    set<int> s;
    for (int i=0;i<n;i++) {
        cin>>v[i];
        s.insert(v[i]);
    }

    map<int,int> mp;
    for (int j=0;int i : s) mp[i] = j++;
    for (int i : v) cout << mp[i] << " ";
}