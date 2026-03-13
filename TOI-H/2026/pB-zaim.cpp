#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define ld long double
#define ull unsigned long long
#define i128 __int128
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ft first
#define sd second
using namespace std;
using namespace __gnu_pbds;
const ll it = 4e18;
const int nmax = 100005;
const int MOD = 1e9 + 7;
const ll I = 1e9;
 
const ll INF = 1e9;
 
void w(int k, char d, vector<char>& p, bool o, ll& c) {
    if (k == 0) return;
    char s = p[k];
    if (s == d) {
        w(k - 1, d, p, o, c);
        return;
    }
    char t;
    if (s == 'A' && d == 'B') t = 'C';
    else if (s == 'A' && d == 'C') t = 'B';
    else if (s == 'B' && d == 'A') t = 'C';
    else if (s == 'B' && d == 'C') t = 'A';
    else if (s == 'C' && d == 'A') t = 'B';
    else if (s == 'C' && d == 'B') t = 'A';
    else t = '?';
    w(k - 1, t, p, o, c);
    if (o) {
        cout << s << ' ' << d << '\n';
    } else {
        ++c;
    }
    p[k] = d;
    w(k - 1, d, p, o, c);
}
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m;
    cin >> m;
    vector<char> q(m + 1);
    int x, y, z;
    cin >> x;
    for (int i = 0; i < x; ++i) {
        int v;
        cin >> v;
        q[v] = 'A';
    }
    cin >> y;
    for (int i = 0; i < y; ++i) {
        int v;
        cin >> v;
        q[v] = 'B';
    }
    cin >> z;
    for (int i = 0; i < z; ++i) {
        int v;
        cin >> v;
        q[v] = 'C';
    }
    bool f = true;
    for (int i = 1; i <= m; ++i) {
        if (q[i] != 'B') {
            f = false;
            break;
        }
    }
    if (f) {
        cout << "0\n";
        return 0;
    }
    vector<char> r = q;
    ll g = 0;
    w(m, 'B', r, false, g);
    cout << g << '\n';
    vector<char> s = q;
    ll h = 0;
    w(m, 'B', s, true, h);
    return 0;
}