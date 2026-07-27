#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    int n;
    cin>>n;
    vector<ll> st;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        st.push_back(a);
        while(st.size()>1){
            if(st.back()!=st[st.size()-2]){
                break;
            }
            ll a = st.back();
            st.pop_back();
            st.pop_back();
            st.push_back(a+1);
        }
    }
    cout << st.size() << '\n';
}