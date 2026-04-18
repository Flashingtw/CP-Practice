#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;

void solve(){
    string a,b;
    cin>>a>>b;
    string st,st2;
    for(char c:a){
        int n = st.size();
        st.push_back(c);
        if(c==')'&&n>=3&&st[n-1]=='x'&&st[n-2]=='x'&&st[n-3]=='('){
            st.pop_back();
            st.pop_back();
            st.pop_back();
            st.pop_back();
            st.push_back('x');
            st.push_back('x');
        }
    }

    for(char c:b){
        int n = st2.size();
        st2.push_back(c);
        if(c==')'&&n>=3&&st2[n-1]=='x'&&st2[n-2]=='x'&&st2[n-3]=='('){
            st2.pop_back();
            st2.pop_back();
            st2.pop_back();
            st2.pop_back();
            st2.push_back('x');
            st2.push_back('x');
        }
    }
    if(st==st2){
        cout << "Yes\n"; 
    }
    else{
        cout << "No\n";
    }
}

int main(){
    int t;
    cin>>t;
    while(t--) solve();
}