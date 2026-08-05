#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1e9+9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> st;
    vector<int> ans;
    for(int i=0;i<n;i++){
        char c=s[i];
        if(c==')'&&!st.empty()&&s[st.back()]=='('){
            while(!ans.empty()&&ans.back()>=st.back()){
                ans.pop_back();
            }
            st.pop_back();
        }
        else{
            if(c=='(') st.push_back(i);
            ans.push_back(i);
        }
    }
    for(int i:ans) cout << s[i];
}