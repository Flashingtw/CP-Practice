#include <iostream>
#include <set>
using namespace std;
int main() {
    int n,q;
    cin>>n;
    set<string> s;
    for (int i=0;i<n;i++) {
        string a;
        cin>>a;
        s.insert(a);
    }
    cin>>q;
    for (int i=0;i<q;i++) {
        string a;
        cin>>a;
        if (s.count(a)) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
            s.insert(a);
        }
    }
}