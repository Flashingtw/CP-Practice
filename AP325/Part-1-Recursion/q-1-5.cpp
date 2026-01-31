#include <iostream>
using namespace std;
string str;
int n,ans=0;
int offset=0;
void solve(int k) {
    for (int i=0;i<4;i++) {
        if (str[offset]=='1') ans+=k*k;
        if (str[offset]=='2') {
            offset++;
            solve(k/2);
        }
        else offset++;
    }
}

int main() {;
    cin>>str>>n;
    solve(n);
    cout << ans;
}