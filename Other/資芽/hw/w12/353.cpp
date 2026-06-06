#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    
    vector<long long> v(n);
    unordered_map<long long, int> freq;
    
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        long long val = 0;
        size_t pos = s.find('.');
        if (pos != string::npos) {
            string frac = s.substr(pos + 1);
            while (frac.length() < 9) {
                frac += "0";
            }
            val = stoll(frac);
        }
        
        v[i] = val;
        freq[val]++;
    }
    
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            long long target = v[i] + v[j];
            if (freq.count(target)) {
                ans += freq[target];
            }
        }
    }
    
    cout << ans << "\n";
}