#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 2000001;
int cnt[N];
void pre(){
    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j+=i){
            cnt[j]++;
        }
    }
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    pre();
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        cout << cnt[a] << '\n';
    }
}