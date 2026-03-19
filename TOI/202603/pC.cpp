#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
void solve(){
    ll a,b,c;
    cin>>a>>b>>c;
    int pa=a%2;
    int pb=b%2;
    int pc=c%2;

    if(pa==pb&&pb==pc){
        cout << "A B C\n";
    }
    else if (pb==pc){
        cout << "A\n";
    }
    else if (pa==pb){
        cout << "C\n";
    }
    else if (pa==pc){
        cout << "B\n";
    }
}
int main(){
    int r;
    cin>>r;
    while(r--) solve();
}