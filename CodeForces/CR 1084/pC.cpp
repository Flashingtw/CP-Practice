#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(n&1) {
        return false;
    }
    stack<char> st;
    for(char c:s){
        if(!st.empty()&&st.top()==c){
            st.pop();
        }
        else{
            st.push(c);
        }
    }
    return st.empty();
}
int main(){
    int t;
    cin>>t;
    while(t--){
        if(solve()){
            cout << "Yes" << "\n";
        }
        else{
            cout << "No" << '\n';
        }
    }
}