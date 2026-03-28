#include <iostream>
#include <set>

using namespace std;
int n;
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    set<int> s;
    while (cin>>n) {
        if (n==0) break;
        if (n>0) {
            s.insert(n);
        }
        if (n<0) {
            if (n==-1) {
                cout << *s.begin() << "\n";
                s.erase(s.begin());
            }
            if (n==-2) {
                auto iter = s.end();
                --iter;
                cout << *iter << " ";
                s.erase(iter);
            }
        }
    }
}